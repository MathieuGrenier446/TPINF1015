#include "Board.h"

Board::Board()
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			map_[i][j] = nullptr;
		}
	}
}