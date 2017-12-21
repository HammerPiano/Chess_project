#include "King.h"

King::King(Point coordinates, bool white) : Piece(coordinates, "King", white)
{
	// Nothing to do.
}

King::~King()
{
	// Nothing to do.
}

void King::move(Point coordinates, const vector<vector<Piece*>>& board)
{
	char x = this->_coordinates.getX();
	char y = this->_coordinates.getY();

	char newX = coordinates.getX();
	char newY = coordinates.getY();

	char xChange = x - newX;
	char yChange = y - newY;
	if (xChange == 1 || xChange == -1 || xChange == 0)
	{
		if (yChange == 1 || yChange == -1 || yChange == 0)
		{
			this->_coordinates = coordinates;
		}
		else
		{
			throw Invalid_Move("6 - Invalid King Move");
		}
	}
	else
	{
		throw Invalid_Move("6 - Invalid King Move");
	}
}
