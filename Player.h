#pragma once
#include "ChessBoard.h"

class Player
{
	public:
	Player(ChessBoard chessBoard);
	void makeMove(coordinate origin, coordinate destination);

	private:
	std::shared_ptr<ChessBoard> chessBoard_;
};