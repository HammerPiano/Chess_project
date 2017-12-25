#include "Rook.h"

Rook::Rook(Point coordinates, bool white) : Piece(coordinates, "Rook", white)
{

}

Rook::~Rook()
{
}

void Rook::move(Point coordinates, const vector<vector<Piece*>>& board)
{
	int i = 0;
	int j = 0;
	char x = this->_coordinates.getX();
	char y = this->_coordinates.getY();

	char newX = coordinates.getX();
	char newY = coordinates.getY();
	
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (board[i][j] != nullptr && board[i][j]->getCoordinates() == coordinates)
			{
				throw Invalid_Move("6 - Invalid Rook Move");
			}
		}
	}
	// or x or y can be different, not both
	if ((newX == x && newY != y) ^ (newX != x && newY == y))
	{
		this->_coordinates = coordinates;
	}
	else
	{
		throw Invalid_Move("6 - Invalid Rook Move");
	}
}