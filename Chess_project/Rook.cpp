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
		Point newCoordinates = this->_coordinates;
		for (size_t i = 0; i < BOARD_LENGHT; i++)
		{
			if (board[x][i] != nullptr)
			{
				break;
			}
			
		}
		this->_coordinates = newCoordinates;
	}
	else
	{
		throw Invalid_Move("6 - Invalid Rook Move");
	}
}
