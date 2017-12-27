#include "Knight.h"

Knight::Knight(Point coordniates, bool white) : Piece(coordniates,"Knight",white)
{

}
Knight::~Knight()
{

}

//points are in the board, checking done in main
void Knight::move(Point coordinates, const vector<vector<Piece*>>& board)
{
	char x = coordinates.getX();
	char y = coordinates.getY();
	Piece* dstPiece = board[y - '1'][x - 'a'];
	if (dstPiece == nullptr || (dstPiece != nullptr && dstPiece->isWhite() != this->isWhite()))
	{
		//update coordinates
		this->_coordinates = coordinates;
	}
	//cant move, checking done in main!
}