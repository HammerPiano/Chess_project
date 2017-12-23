#include "Pawn.h"



Pawn::Pawn(Point coordinates, bool white) : Piece(coordinates,"Pawn",white), _firstMove(firstMove)
{
}


Pawn::~Pawn()
{
}

void Pawn::move(Point coordinates, const vector<vector<Piece*>>& board)
{
	char yDiff = coordinates.getY() - this->_coordinates.getY();
	char xDiff = coordinates.getX() - this->_coordinates.getX();
	Piece* dstPiece = board[coordinates.getY() - '1'][coordinates.getX() - 'a'];
	if (this->_coordinates.getX() == coordinates.getX() && dstPiece == nullptr)
	{
		
		if ((this->_firstMove && yDiff <= 2) || yDiff == 1)
		{
			this->_coordinates = coordinates;
			//after first move soldier cannot move 2 places any longer
			this->_firstMove = false;
		}
		
		else
		{
			throw Invalid_Move("6 - Invalid Pawn move");//invalid piece movement
		}
	}
	//soldier killing someone, assuming points are valid, as we check in board.cpp. Also checking that the colors are different
	else if (abs(xDiff) == 1 && yDiff == 1 && dstPiece != nullptr && dstPiece->isWhite() != this->isWhite())
	{
		this->_coordinates = coordinates
	}
	else
	{
		throw Invalid_Move("6 - Invalid Pawn move");//invalid piece movement
	}
}