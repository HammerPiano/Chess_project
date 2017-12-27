#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(Point coordinates, bool white);
	~Queen();

	virtual void move(Point coordinates, const vector<vector<Piece*>>& board);
};