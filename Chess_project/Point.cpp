#include "Point.h"

char Point::getX()
{
	return this->_x;
}

char Point::getY()
{
	return this->_y;
}

void Point::SetXY(char x, char y)
{
	this->_x = x;
	this->_y = y;
}

void Point::setXY(std::string coordinates)
{
	this->_x = 0;
	this->_y = 0;
}
