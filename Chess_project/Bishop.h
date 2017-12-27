#pragma once
#include "Piece.h"
#include "Invalid_Move.h"

class Bishop : public Piece
{
public:
	Bishop(Point coordinates, bool white);
	~Bishop();
	virtual void move(Point coordinates,const vector<vector<Piece*>>& board) override;
};