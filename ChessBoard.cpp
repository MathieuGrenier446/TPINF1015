#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			coordinate squarePosition(i,j);
			board_[squarePosition] = Square();
		}
	}
	Fou fou = Fou(coordinate(1, 1));
	board_[coordinate(1,1)] = Square(fou);
}

bool ChessBoard::isMoveLegal(coordinate oldPosition, coordinate newPosition)
{

	if(board_[oldPosition].getPiece()->isMovePossible(newPosition))
	{
		board path (board_[oldPosition].getPiece()->findPath(newPosition));
		for(int i = 0; i<8 ; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				if(path[i][j])
				{
					if(!board_[coordinate(i,j)].isAvailable()){
						return false;
					}
				}
			}
		}
	}
	return true;
}

void ChessBoard::movePiece(coordinate oldPosition, coordinate newPosition)
{
	board_[newPosition].getPiece() = std::move(board_[oldPosition].getPiece());
}
