// https://www.spoj.com/problems/INCARDS/

#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;

struct node {
	vector< pair<int, int> > neighbors;
	bool visited;
	int cost;
};

priority_queue< pair<int, int> > q;
int inf = numeric_limits<int>::max();
int total_cost = 0;

void bfs(node graph[], int x)
{
	graph[x].cost = 0;
	q.push(make_pair(0, x));

	while (!q.empty())
	{
		int a = q.top().second;
		q.pop();

		if (graph[a].visited)
		{
			continue;
		}

		graph[a].visited = true;
		total_cost += graph[a].cost;

		for (auto n: graph[a].neighbors)
		{
			int b = n.first;
			int w = n.second;

			if (graph[a].cost + w < graph[b].cost)
			{
				graph[b].cost = graph[a].cost + w;
				q.push(make_pair(-graph[b].cost, b));
			}
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
		int n, e;
		cin >> n >> e;
		node graph[n+1];
		node r_graph[n+1];
		total_cost = 0;

		for (int i=1; i<=n; i++)
		{
			graph[i].visited = false;
			graph[i].cost = inf;
			r_graph[i].visited = false;
			r_graph[i].cost = inf;
		}

		while (e--)
		{
			int a, b, w;
			cin >> a >> b >> w;
			graph[a].neighbors.push_back(make_pair(b, w));
			r_graph[b].neighbors.push_back(make_pair(a, w));
		}

		bfs(graph, 1);
		bfs(r_graph, 1);

		cout << total_cost << "\n";
	}

	return 0;
}
