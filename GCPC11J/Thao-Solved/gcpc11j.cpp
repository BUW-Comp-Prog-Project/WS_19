// http://www.spoj.com/problems/GCPC11J/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int farthest_node;
int max_len = 0;

void dfs(vector<int> graph[], int current_node, int prev_node, int prev_len)
{
	for (auto next_node: graph[current_node])
	{
		if (next_node != prev_node)
		{
			int current_len = prev_len + 1;

			if (max_len < current_len)
			{
				max_len = current_len;
				farthest_node = next_node;
			}

			dfs(graph, next_node, current_node, current_len);
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
		int n;
		cin >> n;
		vector<int> graph[n];
		int e = n - 1;
		max_len = 0;

		while (e--)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		dfs(graph, 0, 0, 0);
		dfs(graph, farthest_node, farthest_node, 0);

		if (max_len % 2 == 0)
		{
			cout << max_len/2 << "\n";
		}

		else
		{
			cout << max_len/2 + 1 << "\n";
		}
	}

	return 0;
}
