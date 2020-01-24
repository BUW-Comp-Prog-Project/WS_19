// https://www.spoj.com/problems/TRVCOST/

#include <iostream>
#include <vector>
#include <queue>
#include <limits> 

using namespace std;

vector< pair<int, int> > road[510];
int visited[510];
int len[510];
int inf = numeric_limits<int>::max();
priority_queue< pair<int, int> > q;

void bfs(int u)
{
	len[u] = 0;
	q.push(make_pair(0, u));

	while(!q.empty())
	{
		int a = q.top().second;
		q.pop();

		if (visited[a])
		{
			continue;
		}

		visited[a] = true;

		for (auto next: road[a])
		{
			int b = next.first;
			int w = next.second;

			if (len[a] + w < len[b])
			{
				len[b] = len[a] + w;
				q.push(make_pair(-len[b], b));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b, w, u, q, v;
	cin >> n;

	for (int i=0; i<=500; i++)
	{
		visited[i] = false;
		len[i] = inf;
	}

	while (n--)
	{
		cin >> a >> b >> w;
		road[a].push_back(make_pair(b, w));
		road[b].push_back(make_pair(a, w));
	}

	cin >> u >> q;
	bfs(u);

	while (q--)
	{
		cin >> v;

		if (len[v] != inf)
		{
			cout << len[v] << "\n";
		}

		else
		{
			cout << "NO PATH" << "\n";
		}
	}

	return 0;
}
