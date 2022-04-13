#pragma once
#include "Piece.h"
#include <memory>

class Square
{
	public:
	Square();
	
	Square(Piece& chessPiece);
	friend class Piece;
	bool isAvailable();
	std::shared_ptr<Piece> getPiece() { return _chessPiece; } 

	protected:
	std::shared_ptr<Piece> _chessPiece;
};