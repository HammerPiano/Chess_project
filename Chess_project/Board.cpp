#include "Board.h"

//initialize vector, that has BOARD_LENGTH vectors of Piece* and each vector has BOARD_LENGTH Piece*
//https://stackoverflow.com/questions/13121469/initializing-a-vector-of-vectors-having-a-fixed-size-with-boost-assign
Board::Board(std::string initialState) : _board(BOARD_LENGTH,vector<Piece*>(BOARD_LENGTH))
{
	char actualY = 0;
	if (initialState.length() != INITIALSTATE_LENGTH)
	{
		throw std::invalid_argument("not enough information about the board");
	}
	if (initialState[64] == '0')
	{
		this->_currentPlayer = true;
	}
	else
	{
		this->_currentPlayer = false;
	}
	this->_firstMove = true;
	for (size_t y = 0; y < BOARD_LENGTH; y++)//num of tiles on board
	{
		//the x is the letter in the board, the y is the line number. lines are the Piece* arrays
		//since I am building the array from right to left (that is how it is represented in the string), i must reverse iterate over the array
		actualY = (char)BOARD_LENGTH - y - 1;
		for (size_t x = 0; x < BOARD_LENGTH; x++)
		{
			Piece* temp = nullptr;
			
			//to access a variable [x][y] you can also do [x*array length + y]
			char piece = initialState[y * BOARD_LENGTH + x];
			
			switch (piece)
			{
			//kings, each king is stored internally
			case 'K':
				temp = new King(Point(x + 'a', actualY + '1'), true);
				this->_whiteKing = temp;
				break;
			case 'k':
				temp = new King(Point(x + 'a', actualY + '1'), false);
				this->_blackKing = temp;
				break;
			//rooks
			case 'R':
			case 'r':
				temp = new Rook(Point(x + 'a', actualY + '1'), piece == 'R');
				break;
			//pawns
			case 'P':
			case 'p':
				temp = new Pawn(Point(x + 'a', actualY + '1'), piece == 'P');
				break;
			case 'N':
			case 'n':
				temp = new Knight(Point(x + 'a', actualY + '1'), piece == 'N');
				break;
			case 'B':
			case 'b':
				temp = new Bishop(Point(x + 'a', actualY + '1'), piece == 'B');
			default:
				break;
			}
			this->_board[actualY][x]= temp;
		}
	}
}

Board::~Board()
{
	for (size_t x = 0; x < BOARD_LENGTH; x++)
	{
		for (size_t y = 0; y < BOARD_LENGTH; y++)
		{
			delete this->_board[x][y];
			this->_board[x][y] = nullptr;
		}
	}
	this->_blackKing = nullptr;
	this->_whiteKing = nullptr;
}

std::string Board::movePiece(Point src, Point dst)
{
	std::string retVal = ERR_NO_ERR;
	//valid point, inside the board
	if (src.getX() >= 'a' && dst.getX() >= 'a' && src.getX() <= 'h' && dst.getX() <= 'h' && src.getY() >= '1' && dst.getY() >= '1' && src.getY() <= '8' && dst.getY() <= '8')
	{
		Piece* srcPiece = this->_board[src.getY() - '1'][src.getX() - 'a'];
		Piece* dstPiece = this->_board[dst.getY() - '1'][dst.getX() - 'a'];
		if (srcPiece != nullptr && srcPiece->isWhite() == this->_currentPlayer)
		{
			if (dstPiece == nullptr || dstPiece->isWhite() != this->_currentPlayer)
			{
				try
				{
					//killing the king!
					if (dstPiece != nullptr && dstPiece->getType() == "King")
					{
						//white player (true) kills the black king, and vice versa
						if (this->_currentPlayer)
						{
							this->_blackKing = nullptr;
						}
						else
						{
							this->_whiteKing = nullptr;
						}
					}
					srcPiece->move(dst, this->_board);
					this->_board[src.getY() - '1'][src.getX() - 'a'] = nullptr;
					this->_board[dst.getY() - '1'][dst.getX() - 'a'] = srcPiece;
					delete dstPiece;
				}
				catch (exception& e)
				{
					retVal = e.what()[0];//first char is the err number
				}
			}
			else
			{
				retVal = ERR_INVALID_DST;
			}

		}
		else
		{
			retVal = ERR_NO_SRC;
		}
		
	}
	if (retVal == ERR_NO_ERR)
	{
		
		
		
		//check if the player did a check on the enemy
		if (isCheck())
		{
			retVal = ERR_CHECK;
		}

		this->_currentPlayer = !this->_currentPlayer;//toggle current player, after valid move
		//check if the player did a check on himself
		if (isCheck())
		{
			retVal = ERR_SELF_CHECK;
			//don't change the current player
			this->_currentPlayer = !this->_currentPlayer;
		}
		
	}
	return retVal;
}

void Board::printBoard()
{
	std::cout << std::endl;
	for (size_t i = 0; i < BOARD_LENGTH; i++)
	{
		
		for (size_t j = 0; j < BOARD_LENGTH; j++)
		{
			if (this->_board[i][j] != nullptr)
			{
				
				if (this->_board[i][j]->isWhite())
				{
					std::cout << "White";
				}
				else
				{
					std::cout << "Black";
				}
				std::cout << this->_board[i][j]->getType();
				
			}
			else
			{
				std::cout << "Empty ";
			}
			std::cout << " " << (char)(j+'a') << (char)(i+'1') << "\t\t";
		}
		
		std::cout << std::endl;
	}
	
}

bool Board::isCheck()
{
	//the other king
	Piece* temp = this->_currentPlayer == false ? this->_whiteKing : this->_blackKing;
	bool check = isCheckmate();
	
	//is checkmate?
	if (!check)
	{
		//check for rooks:
		Point coordinates = temp->getCoordinates();
		for (int i = 0; i < BOARD_LENGTH && !check; i++)
		{
			//check for enemy rook on the same row
			temp = this->_board[i][coordinates.getX() - 'a'];
			if (temp != nullptr)
			{
				check = temp->getType() == "Rook" && temp->isWhite() == this->_currentPlayer;
			}
			//check for enemy rook of the same columb
			temp = this->_board[coordinates.getY() - '1'][i];
			if (!check && temp != nullptr)
			{
				check = temp->getType() == "Rook" && temp->isWhite() == this->_currentPlayer;
			}
		}
		//check for Pawns:
		if (!check)
		{
			char safeRow = 0, yOffset = 0;
			//checking for possiability on other player king
			if (this->_currentPlayer)
			{
				//black player, check for pawns from below
				safeRow = '1';
				yOffset = -1;
			}
			else
			{
				//white player, check for pawn from top left or right
				safeRow = '8';
				yOffset = 1;
			}
			if (coordinates.getY() != safeRow)//top row, no pawn can eat the king
			{
				//king not at right most position
				Piece* lPawn = nullptr;
				Piece* rPawn = nullptr;
				if (coordinates.getX() > 'a')
				{
					lPawn = this->_board[coordinates.getY() + yOffset - '1'][coordinates.getX() - 1 - 'a'];
				}

				if (coordinates.getX() < 'h')
				{
					rPawn = this->_board[coordinates.getY() + yOffset - '1'][coordinates.getX() + 1 - 'a'];
				}
				//check for enemy pawn on either side
				check = (lPawn != nullptr && lPawn->isWhite() == this->_currentPlayer) || (rPawn != nullptr && rPawn->isWhite() == this->_currentPlayer);
			}
		}
	}
	
	return check;
}

bool Board::isCheckmate()
{
	return this->_whiteKing == nullptr || this->_blackKing == nullptr;
}
