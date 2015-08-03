#include "8_Queens_Puzzle.h"


bool Table::SearchSolution()
{
	Table TestSolution;
	int i, j;
	while (1)
	{
		TestSolution = *this;
		//this->PrintTable();
		//this->PrintValidityTable();
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 7; j++)
			{
				if (TestSolution.validity[i][j] == true)
					break;
			}
			if (TestSolution.validity[i][j] == true)
				break;
		}
		if (i > 7)
			i = 7;
		if (TestSolution.validity[i][j] == true)
		{
			TestSolution.AddQueen(i + 1, j + 1);
			if (TestSolution.SearchSolution() == true)
			{
				*this = TestSolution;
				return(true);
			}
			else
			{
				validity[i][j] = false;
			}
		}
		else
		{
			unsigned int Sum = 0;
			for (i = 0; i < 8; i++)
			{
				for (j = 0; j < 8; j++)
				{
					if (TestSolution.state[i][j] == true)
						Sum++;
				}
			}
			if (Sum == 8)
			{
				return(true);
			}
			else
				return(false);
		}
	}
}
void Table::PrintTable()
{
	unsigned int i, j;
	cout << "-----------------" << endl;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			cout << (state[i][j] == true ? "|Q" : "| ");
		}
		cout << "|" << endl << "-----------------" << endl;
	}
}


bool Table::AddQueen(unsigned int row, unsigned int column)
{
	if (row < 1 || row>8 || column < 1 || column>8 || validity[row - 1][column - 1] == false)
		return (false);
	else
	{
		state[row - 1][column - 1] = true;
		unsigned int i;
		for (i = 0; i < 8; i++)
		{
			validity[row - 1][i] = false;
			validity[i][column - 1] = false;
			if (row + column - 2 - i >= 0 && row + column - 2 - i < 8)
				validity[i][row + column - 2 - i] = false;
			if (i - row + column >= 0 && i - row + column < 8)
				validity[i][i - row + column] = false;
		}
		return(true);
	}
}

void Table::PrintValidityTable()
{
	unsigned int i, j;
	cout << "-----------------" << endl;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			/*printf("%s%s", validity[i][j] == true ? "|T" : "|F", j == 7 ? "|\n" : "");*/
			cout << (validity[i][j] == true ? "|T" : "|F");
		}
		cout << "|" << endl << "-----------------" << endl;
	}
}