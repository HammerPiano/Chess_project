#include "Rook.h"

Rook::Rook(Point coordinates, bool white) : Piece(coordinates, "Rook", white)
{

}

Rook::~Rook()
{
}

void Rook::move(Point coordinates, const vector<vector<Piece*>>& board)
{
	char x = this->_coordinates.getX();
	char y = this->_coordinates.getY();

	char newX = coordinates.getX();
	char newY = coordinates.getY();

	if ((newX == x && newY != y) ^ (newX != x && newY == y))
	{
			this->_coordinates = coordinates;
	}
	else
	{
		throw Invalid_Move("6 - Invalid Rook Move");
	}
}
