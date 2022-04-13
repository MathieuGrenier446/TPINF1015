#pragma once
#include <iostream>
#include "ChessBoard.h"

class Player
{
	public:
	Player();
	void makeMove(coordinate origin, coordinate destination);

	private:
	ChessBoard chessBoard;
};