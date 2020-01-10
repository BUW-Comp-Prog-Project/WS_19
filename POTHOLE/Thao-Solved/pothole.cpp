// https://www.spoj.com/problems/POTHOLE/

#include <iostream>
#include <queue>
#include <limits>

using namespace std;

int inf = numeric_limits<int>::max();

bool bfs(int path[201][201], int s, int d, int parent[])
{
	bool visited[d+1];

	for (int i=1; i<=d; i++)
	{
		visited[i] = false;
	}

	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		if (current == d) break;

		for (int next=s+1; next<=d; next++)
		{
			if (!visited[next] && path[current][next] > 0)
			{
				q.push(next);
				parent[next] = current;
				visited[next] = true;
			}
		}
	}

	return visited[d];
}

int edmonds_karp(int path[201][201], int s, int d)
{
	int parent[d+1];
	int max_flow = 0;

	while (bfs(path, s, d, parent))
	{
		int path_flow = inf;

		for (int current=d; current!=s; current=parent[current])
		{
			int prev = parent[current];
			path_flow = min(path_flow, path[prev][current]);
		}

		for (int current=d; current!=s; current=parent[current])
		{
			int prev = parent[current];
			path[prev][current] -= path_flow;
			path[current][prev] += path_flow;
		}

		max_flow += path_flow;
	}

	return max_flow;
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

		int path[201][201];

		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
			{
				path[i][j] = 0;
			}
		}

		for (int i=1; i<n; i++)
		{
			int connect;
			cin >> connect;

			while (connect--)
			{
				int j;
				cin >> j;

				if (i == 1 || j == n)
				{
					path[i][j] = 1;
				}

				else
				{
					path[i][j] = inf;
				}
			}
		}

		cout << edmonds_karp(path, 1, n) << "\n";
	}

	return 0;
}
