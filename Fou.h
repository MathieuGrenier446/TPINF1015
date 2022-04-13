#pragma once
#include "Piece.h"
#include <string>

class Fou : Piece
{	
	public:

	Fou(std::string colour);

	bool isPathClear(coordinate origin, coordinate destination, std::map<coordinate, std::shared_ptr<Piece>> board);
	bool isMovePossible(coordinate origin, coordinate destination);

	private:
	std::string colour_;
	char type_;
	
};