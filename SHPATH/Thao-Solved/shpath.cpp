// https://www.spoj.com/problems/SHPATH/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

int inf = numeric_limits<int>::max();

int bfs(int n, int s, int d, vector< pair<int, int> > graph[])
{
	bool visited[n+1];
	int cost[n+1];
	priority_queue< pair<int, int> > q;

	for (int i=0; i<=n; i++)
	{
		visited[i] = false;
		cost[i] = inf;
	}

	cost[s] = 0;
	q.push(make_pair(0, s));

	while(!q.empty())
	{
		int a = q.top().second;
		q.pop();

		if (visited[a]) continue;

		visited[a] = true;

		if (a == d) break;

		for (auto next: graph[a])
		{
			int b = next.first;
			int w = next.second;

			if (cost[a] + w < cost[b])
			{
				cost[b] = cost[a] + w;
				q.push(make_pair(-cost[b], b));
			}
		}
	}

	return cost[d];
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
		int cities = n;
		int ind = 1;
		vector< pair<int, int> > graph[n+1];
		unordered_map<string, int> name;

		while (cities--)
		{
			string a;
			int connect;
			cin >> a >> connect;
			name[a] = ind;

			while (connect--)
			{
				int b, w;
				cin >> b >> w;
				graph[ind].push_back(make_pair(b, w));
			}

			ind++;
		}

		int path;
		cin >> path;

		while (path--)
		{
			string source, destination;
			cin >> source >> destination;
			int s, d;
			s = name[source];
			d = name[destination];

			cout << bfs(n, s, d, graph) << "\n";
		}
	}

	return 0;
}
