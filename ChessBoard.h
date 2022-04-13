#pragma once
#include <map>
#include <memory>
#include <iostream>
#include "Fou.h"


using coordinate = std::tuple<int, int>;

class ChessBoard
{
	public:
	ChessBoard();
	
	std::shared_ptr<Piece>& operator[](coordinate position)
	{
		return board_[position];
	}
	
	bool isMoveLegal(coordinate oldPosition, coordinate newPosition);
	void movePiece(coordinate oldPosition, coordinate newPosition);
	
	std::shared_ptr<Piece> getPiece(coordinate position) { return board_[position]; };

	protected:

	std::map<coordinate, std::shared_ptr<Piece>> board_;

	private:
	void placePiece(std::string colour, coordinate position, Piece piece);
};