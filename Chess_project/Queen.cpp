#include "Queen.h"

Queen::Queen(Point coordinates, bool white) : Piece(coordinates, "Queen", white)
{
}

Queen::~Queen()
{
}

void Queen::move(Point coordinates, const vector<vector<Piece*>>& board)
{
	char curr_Y = this->_coordinates.getX() - 'a';
	char curr_X = this->_coordinates.getY() - '1';
	char new_Y = coordinates.getX() - 'a';
	char new_X = coordinates.getY() - '1';
	bool retVal = true;
	int i = 0, j = 0;
	if (curr_Y<new_Y && curr_X == new_X)
	{
		for (i = curr_Y + 1; i<new_Y && retVal == true; i++)
		{
			if (board[i][new_X] != nullptr)
			{
				retVal = false;
			}
		}
	}
	else if (curr_Y>new_Y && curr_X == new_X)
	{
		for (i = curr_Y - 1; i>new_Y && retVal == true; i--)
		{
			if (board[i][new_X] != nullptr)
			{
				retVal = false;
			}
		}
	}
	else if (curr_X>new_X && curr_Y == new_Y)
	{
		for (j = curr_X - 1; j>new_X && retVal == true; j--)
		{
			if (board[curr_Y][j] != nullptr)
			{
				retVal = false;
			}
		}
	}
	else if (curr_X<new_X && curr_Y == new_Y)
	{
		for (j = curr_X + 1; j<new_X && retVal == true; j++)
		{
			if (board[curr_Y][j] != nullptr)
			{
				retVal = false;
			}
		}
	}
	else if (curr_Y<new_Y && curr_X<new_X) // right and down
	{
		i = curr_Y + 1;
		j = curr_X + 1;
		while (i<new_Y && j<new_X && retVal == true)
		{
			if (board[i][j] != nullptr)
			{
				retVal = false;
			}
			i++;
			j++;
		}
	}
	else if (curr_Y>new_Y && curr_X<new_X) // right and up
	{
		i = curr_Y - 1;
		j = curr_X + 1;
		while (i>new_Y && j<new_X && retVal == true)
		{
			if (board[i][j] != nullptr)
			{
				retVal = false;
			}
			i--;
			j++;
		}
	}
	else if (curr_Y>new_Y && curr_X>new_X) // left and up
	{
		i = curr_Y - 1;
		j = curr_X - 1;
		while (i>new_Y && j>new_X && retVal == true)
		{
			if (board[i][j] != nullptr)
			{
				retVal = false;
			}
			i--;
			j--;
		}
	}
	else if (curr_Y<new_Y && curr_X>new_X) // left and down
	{
		i = curr_Y + 1;
		j = curr_X - 1;
		while (i<new_Y && j>new_X && retVal == true)
		{
			if (board[i][j] != nullptr)
			{
				retVal = false;
			}
			i++;
			j--;
		}
	}
	if (retVal)
	{
		this->_coordinates = coordinates;
	}
}
