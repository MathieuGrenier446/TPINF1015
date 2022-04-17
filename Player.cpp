#include "Player.h"

Player::Player(ChessBoard chessBoard)
{
	chessBoard_ = std::make_shared<ChessBoard>(chessBoard);
}

void Player::makeMove(coordinate origin, coordinate destination)
{
	if(chessBoard_->isMoveLegal(origin, destination))
	{
		chessBoard_->movePiece(origin, destination);
	}
}