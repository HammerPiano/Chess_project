#pragma once
#include "Piece.h"
class Pawn : public Piece
{
public:
	Pawn(Point coordinates, bool white, bool firstMove);
	virtual void move(Point coordinates) override;
	~Pawn();
private:
	bool _firstMove;
};

