#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(Point coordinates, bool white);
	~King();

	virtual void move(Point coordinates);
};