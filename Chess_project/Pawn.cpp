#include "Pawn.h"



Pawn::Pawn(Point coordinates, bool white, bool firstMove) : Piece(coordinates,"Pawn",white), _firstMove(firstMove)
{
}


Pawn::~Pawn()
{
}