#include "Board.h"
#include<map>
using namespace std;
#include<string>
#include <iostream>
map<pair<int,int>,string> myMap;
Board::Board()
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			myMap[{i,j}] = nullptr;
		}
	}
}
int main()
{
	cout << myMap[{1, 1}];
}