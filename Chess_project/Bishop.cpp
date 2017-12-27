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
		Point dst(0, 0);
		for (int y = 0; y < BOARD_LENGTH ; y++)
		{
			for (int x = 0; x < BOARD_LENGTH ; x++)
			{
				Piece* temp = board[y][x];
				if (temp != nullptr)
				{
					if (temp->isWhite() == this->isWhite())
					{
						x--;
						y--;
						if (x < 0 || y < 0)
						{
							throw Invalid_Move("6 - invalid bishop move");
						}
						dst.setXY(x + 'a', y + '0');
						break;
					}
					else
					{
						dst.setXY(x + 'a', y + '0');
						break;
					}
				}
			}
		}
		this->_coordinates = dst;
	}
}