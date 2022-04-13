#include "Fou.h"

std::shared_ptr<std::shared_ptr<int[]>[]> Fou::findPath(coordinate destination)
{
	board path;
	path = std::make_shared<std::shared_ptr<int[]>>(8);

	for(int i = 0; i < 8; i++)
	{
		path[i] = std::make_shared<int[]>(8);
	}

	int xDirection = xPos(position_) > xPos(destination) ? 1 : -1;
	int yDirection = yPos(position_) > yPos(destination) ? 1 : -1;

	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(i < abs(xPos(position_) - xPos(destination)) && j < abs(yPos(position_) - yPos(destination)))
			{
				path[i][j] = 1;
			}
			else
			{
				path[i][j] = 0;
			}
		}
	}
	return path;
};

bool Fou::isMovePossible(coordinate destination)
{
	return abs(xPos(position_) - xPos(destination)) == abs(yPos(position_) - yPos(destination));
};
