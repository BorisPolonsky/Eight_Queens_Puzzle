#include <iostream>

#ifndef __8_Queens_Puzzle_h
#define __8_Queens_Puzzle_h
using namespace std;

typedef int STATUS;

class Table
{
public:
	Table()
	{
		int i, j;
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				state[i][j] = false;
				validity[i][j] = true;
			}
		}
	}
	bool SearchSolution();
	void PrintTable();
	bool AddQueen(unsigned int, unsigned int);
private:
	bool state[8][8];
	bool validity[8][8];
	void PrintValidityTable();
};

#endif
