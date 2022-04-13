#include "Square.h"

Square::Square()
{
	_chessPiece = nullptr;
}

Square::Square(Piece& chessPiece){

	_chessPiece = std::make_shared<Piece>(chessPiece);
}

bool Square::isAvailable()
{
	return(_chessPiece==nullptr);
}