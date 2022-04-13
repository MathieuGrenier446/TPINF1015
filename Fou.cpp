#include "Fou.h"

Fou::Fou(std::string colour)
{
	colour_ = colour;
}

bool Fou::isPathClear(coordinate origin, coordinate destination, std::map<coordinate, std::shared_ptr<Piece>> board)
{
	int xDirection = xPos(origin) > xPos(destination) ? 1 : -1;
	int yDirection = yPos(origin) < yPos(destination) ? 1 : -1;

	for(int i = 0; i < abs(xPos(origin)-xPos(destination)); i++)
	{
		for(int j = 0; j < abs(yPos(origin) - yPos(destination)); j++)
		{
			if(!(board[coordinate(xPos(origin) + xDirection * i, yPos(origin) + yDirection * j)] == nullptr))
			{
				return false;
			}
		}
	}
	return true;
};

bool Fou::isMovePossible(coordinate origin, coordinate destination)
{
	return abs(xPos(origin) - xPos(destination)) == abs(yPos(origin) - yPos(destination));
};
