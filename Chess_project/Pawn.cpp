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
	if (this->_coordinates.getX() == coordinates.getX())
	{
		if ((this->_firstMove && yDiff <= 2) || yDiff == 1)
		{
			this->_coordinates = coordinates;
		}
		else
		{
			throw Invalid_Move("6");//invalid piece movement
		}
	}
	else
	{
		throw Invalid_Move("6");//invalid piece movement
	}
}