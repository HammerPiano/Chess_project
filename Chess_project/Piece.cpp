#include "Piece.h"
//ctor and dtor
Piece::Piece(Point coordinates, std::string type, bool white) :_coordinates(coordinates), _type(type), _white(white)
{
	//nothing todo
}

Piece::~Piece()
{

}

//getters
bool Piece::isWhite()
{
	return this->_white;
}

std::string Piece::getType()
{
	return this->_type;
}

Point Piece::getCoordinates()
{
	return this->_coordinates;
}

//move isn't implemented here, because it is unique for each class