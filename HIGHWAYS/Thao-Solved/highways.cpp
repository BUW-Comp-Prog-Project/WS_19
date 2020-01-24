// http://www.spoj.com/problems/HIGHWAYS/

#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

int inf = numeric_limits<int>::max();

string dijkstra (int n, int start, int end, vector< pair<int, int> > graph[])
{
	priority_queue< pair<int, int> > q;
	bool visited[n];
	int times[n];

	for (int i=1; i<n; i++)
	{
		visited[i] = false;
		times[i] = inf;
	}

	times[start] = 0;
	q.push(make_pair(0, start));

	while(!q.empty())
	{
		int a = q.top().second;
		q.pop();

		if (a == end) return to_string(times[a]);

		if (visited[a]) continue;

		visited[a] = true;

		for (auto next: graph[a])
		{
			int b = next.first;
			int w = next.second;

			if (times[a] + w < times[b])
			{
				times[b] = times[a] + w;
				q.push(make_pair(-times[b], b));
			}
		}
	}

	return "NONE";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;

	while (cases--)
	{
		int n, e, start, end;
		cin >> n >> e >> start >> end;
		vector< pair<int, int> > graph[n+1];

		while (e--)
		{
			int a, b, w;
			cin >> a >> b >> w;

			graph[a].push_back(make_pair(b, w));
			graph[b].push_back(make_pair(a, w));
		}

		cout << dijkstra(n+1, start, end, graph) << "\n";
	}

	return 0;
}
