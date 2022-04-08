#pragma once
#include <map>
#include <memory>
#include "Square.h"

using coordinate = std::tuple<char, int>;

class ChessBoard : Square
{
	public:
	ChessBoard();

	Square& operator[](coordinate position)
	{
		return board_[position];
	}
	
	void movePiece(coordinate oldPosition, coordinate newPosition);

	protected:
	std::map<coordinate, Square> board_; 
};