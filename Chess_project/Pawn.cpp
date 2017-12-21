#include "Pawn.h"



Pawn::Pawn(Point coordinates, bool white, bool firstMove) : Piece(coordinates,"Pawn",white), _firstMove(firstMove)
{
}


Pawn::~Pawn()
{
}

void Pawn::move(Point coordinates)
{
	if (this->_coordinates.getX() == coordinates.getX())
	{
		if (1)
		{
			throw Invalid_Move("test");
		}
	}
}