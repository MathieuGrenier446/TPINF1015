#pragma once
#include <vector>
#include <memory>
#include "Piece.h"

class Board
{
	public:
	Board();

	private:
	std::vector<std::vector<std::unique_ptr<Piece>>> map_; 
}