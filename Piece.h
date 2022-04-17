#pragma once
#include <tuple>
#include <vector>
#include <map>
#include <memory>

class Piece
{
	public:
	using coordinate = std::tuple<int, int>;

	Piece(){};
	Piece(std::string colour)
	{
		colour_ = colour;
	}
	
	virtual bool isPathClear(coordinate origin, coordinate destination, std::map<coordinate, std::shared_ptr<Piece>> board) = 0;
	virtual bool isMovePossible(coordinate origin, coordinate destination) = 0;

	protected:

	virtual int xPos(coordinate position) { return std::get<0>(position); }
	virtual int yPos(coordinate position) { return std::get<1>(position); }

	private:
	std::string colour_;
};