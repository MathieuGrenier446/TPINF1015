#pragma once
#include <tuple>
#include <memory>

class Piece
{
	public:
	using coordinate = std::tuple<int, int>;
	using board = std::shared_ptr<std::shared_ptr<int[]>[]>;

	Piece(){};

	virtual board findPath(coordinate destination) = 0;
	virtual bool isMovePossible(coordinate destination) = 0;
	virtual int xPos(coordinate position) { return std::get<0>(position); } 
	virtual int yPos(coordinate position) { return std::get<1>(position); }

	private:
	coordinate position_;
};