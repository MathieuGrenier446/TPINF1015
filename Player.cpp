#include "Player.h"

Player::Player()
{
}

void Player::makeMove(coordinate origin, coordinate destination)
{
	if(chessBoard.isMoveLegal(origin, destination))
	{
		chessBoard.movePiece(origin, destination);
	}
}