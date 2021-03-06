#pragma once
#include "Piece.h"
class Pawn : public Piece
{
public:
	Pawn(Point coordinates, bool white);
	virtual void move(Point coordinates,const vector<vector<Piece*>>& board) override;
	~Pawn();
private:
	bool _firstMove;
};

