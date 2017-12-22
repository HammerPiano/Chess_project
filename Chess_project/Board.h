#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Piece.h"
#include "Rook.h"
#include "King.h"
#include <exception>

//according to the presentation, gets a 66 long string
#define INITIALSTATE_LENGTH 65
#define ERR_NO_ERR "0"
#define ERR_CHECK "1"
#define ERR_NO_SRC "2"
#define ERR_INVALID_DST "3"
#define ERR_SELF_CHECK "4"
#define ERR_INVALID_INDEX "5"
#define ERR_INVALID_MOVE "6"
#define ERR_SAME_INDEXES "7"
#define ERR_CHECK_MATE "8"
using std::vector;
using std::exception;
class Board
{
public :
	Board(std::string initialState);
	~Board();
	std::string movePiece(Point src, Point dst);
	void printBoard();
	bool isCheck();
	bool isCheckmate();
private:
	vector<vector<Piece*>> _board;
	bool _firstMove;
	bool _currentPlayer;//true: white, false: black
	Piece* _whiteKing;
	Piece* _blackKing;
};