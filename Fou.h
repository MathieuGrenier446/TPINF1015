#pragma once
#include "Piece.h"

class Fou : Piece
{	
	public:

	Fou(coordinate position);

	board findPath(coordinate destination);
	bool isMovePossible(coordinate destination);

	private:
	coordinate position_;
};