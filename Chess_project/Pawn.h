#pragma once
#include "Piece.h"
class Pawn : public Piece
{
public:
	Pawn(Point coordinates, bool white, bool firstMove);
	~Pawn();
private:
	bool _firstMove;
};

