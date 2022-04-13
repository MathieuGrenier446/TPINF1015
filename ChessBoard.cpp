#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			coordinate squarePosition(i,j);
			board_[squarePosition] = nullptr;
		}
	}
}

bool ChessBoard::isMoveLegal(coordinate origin, coordinate destination)
{
	std::shared_ptr<Piece> piece = getPiece(origin);

	if(piece->isMovePossible(origin, destination))
	{
		return piece->isPathClear(origin, destination, board_);
	}
	else
	{
		return false;
	}
}

void ChessBoard::movePiece(coordinate oldPosition, coordinate newPosition)
{
	board_[newPosition] = std::move(board_[oldPosition]);
}

void ChessBoard::placePiece(std::string colour, coordinate position, Piece piece)
{
	board_[position] = std::make_shared<Piece>(colour);
}

