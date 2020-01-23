#include <iostream>
using namespace std;
int countPossibilities = 0;
int inputField[7][8];
bool cellUsed[7][8];
bool stoneUsed[7][7];

void solve(int i, int j, int counter)
{
	if (counter == 28)
	{
		countPossibilities++;
		return;
	}

	cellUsed[i][j] = true;
	int firstSquare, secondSquare;

	//horizontal
	if (j < 7)
	{
		firstSquare = inputField[i][j + 1];
		secondSquare = inputField[i][j];
		if(firstSquare > secondSquare) 
			swap(firstSquare, secondSquare);

		if (stoneUsed[firstSquare][secondSquare] == false && cellUsed[i][j + 1]==false)
		{
			stoneUsed[firstSquare][secondSquare] = true;
			cellUsed[i][j + 1] = true;
			int next_i = 0, next_j = 0;
			bool found = false;
			for (int _i = i; _i < 7; _i++)
			{
				for (int _j = 0; _j < 8; _j++)
				{
					if (cellUsed[_i][_j] == false)
					{
						next_i = _i, next_j = _j;
						found = true;;
						break;
					}
				}
				if (found == true)
					break;
			}

			solve(next_i, next_j, counter + 1);
			cellUsed[i][j + 1] = false;
			stoneUsed[firstSquare][secondSquare] = false;
		}
	}
	//vertical
	if (i < 6)
	{
		firstSquare = inputField[i + 1][j];
		secondSquare = inputField[i][j];
		if(firstSquare > secondSquare) 
			swap(firstSquare, secondSquare);

		if (stoneUsed[firstSquare][secondSquare] == false && cellUsed[i + 1][j] == false)
		{
			stoneUsed[firstSquare][secondSquare] = true;
			cellUsed[i + 1][j] = true;

			bool found = false;

			int next_i = 0, next_j = 0;
			for (int _i = i; _i < 7; _i++)
			{
				for (int _j = 0; _j < 8; _j++)
				{
					if (cellUsed[_i][_j] == false)
					{
						next_i = _i, next_j = _j;
						found = true;
						break;
					}
				}
				if (found == true)
					break;
			}
			//if (found == true)
			solve(next_i, next_j, counter + 1);
			cellUsed[i + 1][j] = false;
			stoneUsed[firstSquare][secondSquare] = false;
		}
	}
	cellUsed[i][j] = false;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> inputField[i][j];
			}
		}

		countPossibilities = 0;
		solve(0, 0, 0);
		cout << countPossibilities << endl;
	}
	return 0;
}