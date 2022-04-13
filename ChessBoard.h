#pragma once
#include <map>
#include <memory>
#include "Square.h"

using coordinate = std::tuple<int, int>;

class ChessBoard
{
	public:
	using board = std::shared_ptr<std::shared_ptr<int[]>[]>;
	ChessBoard();
	
	Square& operator[](coordinate position)
	{
		return board_[position];
	}
	
	bool isMoveLegal(coordinate oldPosition, coordinate newPosition);

	protected:
	std::map<coordinate, Square> board_; 
};