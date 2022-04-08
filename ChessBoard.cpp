#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	char horizontalPositions[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			std::tuple<char, int> squarePosition (horizontalPositions[i],j);
			board_[squarePosition] = Square();
		}
	}
}

void ChessBoard::movePiece(coordinate oldPosition, coordinate newPosition)
{
	board_[newPosition].getPiece() = std::move(board_[oldPosition].getPiece());
}