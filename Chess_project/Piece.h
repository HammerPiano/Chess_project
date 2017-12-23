#pragma once
#include "Point.h"
#include <iostream>
#include <string>
#include <vector>
#include "Invalid_Move.h"
using std::vector;
#define BOARD_LENGTH 8
class Piece
{
public:
	Piece(Point coordinates, std::string type, bool white);
	virtual ~Piece();
	bool isWhite();
	std::string getType();
	Point getCoordinates();
	virtual void move(Point coordinates,const vector<vector<Piece*>>& board) = 0;
protected:
	Point _coordinates;
private:
	std::string _type;
	bool _white;
};

