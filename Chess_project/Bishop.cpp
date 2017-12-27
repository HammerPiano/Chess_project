#include "Bishop.h"
Bishop::Bishop(Point coordinates, bool white) : Piece(coordinates,"Bishop",white)
{

}

Bishop::~Bishop()
{

}

void Bishop::move(Point coordinates, const vector<vector<Piece*>>& board)
{
	char deltaX = abs(coordinates.getX() - this->_coordinates.getX());
	char deltaY = abs(coordinates.getY() - this->_coordinates.getY());
	
	if (deltaX != deltaY)
	{
		throw Invalid_Move("6 - invalid bishop move");
	}
	else
	{
		this->_coordinates = coordinates;
	}
}