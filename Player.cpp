#include "Player.h"

Player::Player()
{
}

void Player::makeMove(coordinate origin, coordinate destination)
{
	if(chessBoard[destination].isAvailable())
	{
		chessBoard.movePiece(origin, destination);
	}
}