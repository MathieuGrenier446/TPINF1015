#include "Player.h"

Player::Player(std::string colour)
{
	_colour = colour;
}

void Player::makeMove(coordinate origin, coordinate destination)
{
	if(chessBoard[destination].isAvailable())
	{
		chessBoard.movePiece(origin, destination);
	}
}