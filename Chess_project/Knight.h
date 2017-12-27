#pragma once
#include "Piece.h"
#include "Invalid_Move.h"

class Knight : public Piece
{
public:
	Knight(Point coordinates, bool white);
	~Knight();
	virtual void move(Point coordinates, const vector<vector<Piece*>>& board) override;
};