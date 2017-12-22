#include "Board.h"

Board::Board(std::string initialState)
{
	if (initialState.length() != INITIALSTATE_LENGTH)
	{
		throw std::invalid_argument("not enough information about the board");
	}
	this->_currentPlayer = initialState[65] == '0' ? false : true;
	this->_firstMove = true;
	for (size_t x = 0; x < BOARD_LENGHT; x++)//num of tiles on board
	{
		for (size_t y = 0; y < BOARD_LENGHT; y++)
		{

			Piece* temp = nullptr;
			switch (initialState[x * BOARD_LENGHT + y])
			{
			case 'K':
				King(Point(x + 'A', y + '0'), true);
				break;
			case 'k':
				King(Point(x + 'A', y + '1'), false);
				break;
			case 'R':
				Rook(Point(x + 'A', y + '1'), true);
				break;
			case 'r':
				Rook(Point(x + 'A', y + '1'), false);
				break;
			default:
				break;
			}
			this->_board[x][y] = temp;
		}
	}
}

Board::~Board()
{
	for (size_t x = 0; x < BOARD_LENGHT; x++)
	{
		for (size_t y = 0; y < BOARD_LENGHT; y++)
		{
			delete this->_board[x][y];
		}
	}
}

std::string Board::movePiece(Point src, Point dst)
{
	std::string retVal = ERR_NO_ERR;
	//valid point
	if (src.getX() >= 'A' && dst.getX() >= 'A' && src.getX() <= 'H' && dst.getX() <= 'H' && src.getY() >= '1' && dst.getY() >= '1' && src.getY() <= '8' && dst.getY() <= '8')
	{
		Piece* srcPiece = this->_board[src.getX() - 'A'][src.getY() - '1'];
		Piece* dstPiece = this->_board[dst.getX() - 'A'][dst.getY() - '1'];
		if (srcPiece != nullptr && srcPiece->isWhite() == this->_currentPlayer)
		{
			if (dstPiece == nullptr || dstPiece->isWhite() != this->_currentPlayer)
			{
				try
				{
					srcPiece->move(dst, this->_board);
					this->_board[src.getX() - 'A'][src.getY() - '1'] = nullptr;
					this->_board[dst.getX() - 'A'][dst.getY() - '1'] = srcPiece;
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
	return retVal;
}
