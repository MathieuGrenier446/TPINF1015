#pragma once
#include <map>
#include <memory>
#include "Piece.h"

class Board
{
	public:
	Board();

	private:
	std::map<std::tuple<int,int>, std::unique_ptr<Piece>> map_; 
};