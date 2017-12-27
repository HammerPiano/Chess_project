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
	char x = this->_coordinates.getX() - 'a';
	char y = this->_coordinates.getY() - '1';

	char newX = coordinates.getX() - 'a';
	char newY = coordinates.getY() - '1';
	
	if (board[newY][newX] != nullptr && board[newY][newX]->isWhite() == this->isWhite())
	{
		throw Invalid_Move("6 - Invalid rook move");
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