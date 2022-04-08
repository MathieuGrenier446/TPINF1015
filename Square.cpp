#include "Square.h"

Square::Square()
{
	_isAvailable = true;
}

Square::Square(Piece& chessPiece){

	_chessPiece = std::make_shared<Piece>(chessPiece);
	_isAvailable = false;
}
