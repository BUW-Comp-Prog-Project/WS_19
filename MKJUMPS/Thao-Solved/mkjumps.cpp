// https://www.spoj.com/problems/MKJUMPS/

#include <iostream>

using namespace std;

int board[10][10];
int rows[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int cols[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int moves = 0;

void jump(int row, int column, int counter)
{
	if (counter > moves)
	{
		moves = counter;
	}

	for (int i=0; i<8; i++)
	{
		int next_row = row + rows[i];
		int next_column = column + cols[i];

		if (next_row >= 0 && next_row < 10 && next_column >= 0 && next_column < 10 && board[next_row][next_column] == 0)
		{
			board[next_row][next_column] = 1;
			jump(next_row, next_column, counter+1);
			board[next_row][next_column] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c = 1, n;

	for (;;)
	{
		cin >> n;

		if (n == 0)
		{
			break;
		}

		int x, y, possible_moves = 0;

		for (int i=0; i<10; i++)
		{
			for (int j=0; j<10; j++)
			{
				board[i][j] = -1;
			}
		}

		for (int i=0; i<n; i++)
		{
			cin >> x >> y;

			for (int j=0; j<y; j++)
			{
				board[i][x+j]++;
				possible_moves++;
			}
		}

		moves = 0;
		board[0][0] = 1;
		jump(0, 0, 1);

		if (possible_moves - moves == 1)
		{
			cout << "Case " << c << ", " << possible_moves - moves << " square can not be reached." << "\n";
		}

		else
		{
			cout << "Case " << c << ", " << possible_moves - moves << " squares can not be reached." << "\n";
		}

		c++;
	}

	return 0;
}
