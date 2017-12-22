#pragma once
#include "Point.h"
#include <iostream>
#include <string>
#include <vector>
#include "Invalid_Move.h"
using std::vector;
#define BOARD_LENGHT 8
class Piece
{
public:
	Piece(Point coordinates, std::string type, bool white);
	~Piece();
	bool isWhite();
	std::string getType();
	virtual void move(Point coordinates,const vector<vector<Piece*>>& board) = 0;
protected:
	Point _coordinates;
private:
	std::string _type;
	bool _white;
};

