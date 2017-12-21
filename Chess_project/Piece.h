#pragma once
#include "Point.h"
#include <iostream>
#include <string>
#include "Invalid_Move.h"
class Piece
{
public:
	Piece(Point coordinates, std::string type, bool white);
	~Piece();
	bool isWhite();
	std::string getType();
	virtual void move(Point coordinates) = 0;
protected:
	Point _coordinates;
private:
	std::string _type;
	bool _white;
};

