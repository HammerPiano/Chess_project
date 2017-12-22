#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(Point coordinates, bool white);
	~Rook();

	virtual void move(Point coordinates, const vector<vector<Piece*>>& board);
};