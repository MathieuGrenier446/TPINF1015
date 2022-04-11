#pragma once
#include <iostream>
#include "ChessBoard.h"

class Player : ChessBoard
{
	public:
	Player(std::string colour);
	void makeMove(coordinate origin, coordinate destination);

	private:
	ChessBoard chessBoard;
};