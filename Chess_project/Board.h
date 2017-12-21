#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include <exception>

//according to the presentation, gets a 66 long string
#define INITIALSTATE_LENGTH 66
using std::vector;
class Board
{
public :
	Board(std::string initialState);
	~Board();
	void movePiece(Point src, Point dst);
	void printBoard();
	bool isCheck();
	bool isCheckmate();
private:
	vector<vector<Piece*>> _board;
	bool _firstMove;
	bool _currentPlayer;//true: white, false: black
};