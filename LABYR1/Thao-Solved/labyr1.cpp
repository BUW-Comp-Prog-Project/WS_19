// http://www.spoj.com/problems/LABYR1/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int max_len = 0;
int farthest_block;

void dfs(vector<int> graph[], int current_block, int prev_block, int prev_len)
{
	for (auto next_block: graph[current_block])
	{
		if (next_block != prev_block)
		{
			int current_len = prev_len + 1;

			if (max_len < current_len)
			{
				max_len = current_len;
				farthest_block = next_block;
			}

			dfs(graph, next_block, current_block, current_len);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;

	while (cases--)
	{
		int c, r;
		cin >> c >> r;
		int prev_row[c];
		memset(prev_row, -1, sizeof(prev_row));
		int ind = 0;
		vector<int> graph[r*c];
		int start = 0;
		max_len = 0;

		while (r--)
		{
			char mark;

			for (int i=0; i<c; i++)
			{
				cin >> mark;
				if (mark == '.')
				{
					int upper = prev_row[i];
					int current = ind++;

					if (upper != -1)
					{
						graph[current].push_back(upper);
						graph[upper].push_back(current);
						start = current;
					}

					if (i > 0)
					{
						int left = prev_row[i-1];

						if (left != -1)
						{
							graph[current].push_back(left);
							graph[left].push_back(current);
							start = current;
						}
					}

					prev_row[i] = current;
				}

				else
				{
					prev_row[i] = -1;
				}
			}
		}

		dfs(graph, start, start, 0);
		dfs(graph, farthest_block, farthest_block, 0);
		cout << "Maximum rope length is " << max_len << ".\n";
	}

	return 0;
}
