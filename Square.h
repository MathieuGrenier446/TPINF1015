#pragma once
#include "Piece.h"
#include <memory>

class Square
{
	public:
	Square();
	Square(Piece& chessPiece);
	bool isAvailable() { return _isAvailable; }
	std::shared_ptr<Piece> getPiece() { return _chessPiece; }

	protected:
	bool _isAvailable = true; 
	std::shared_ptr<Piece> _chessPiece;
};