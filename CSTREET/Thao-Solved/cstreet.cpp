// https://www.spoj.com/problems/CSTREET/

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

int prim(vector< pair<int, int> > graph[], int n)
{
	priority_queue< pair<int, int> > q;
	bool visited[n];
	memset(visited, false, sizeof(visited));
	q.push(make_pair(0, 1));
	int mst = 0;

	while (!q.empty())
	{
		int a = q.top().second;
		int l = q.top().first;
		q.pop();

		if (visited[a]) continue;

		visited[a] = true;
		mst -= l;

		for (auto next: graph[a])
		{
			int b = next.first;
			int w = next.second;
			q.push(make_pair(-w, b));
		}
	}

	return mst;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases, p, n, e;
	cin >> cases;

	while (cases--)
	{
		cin >> p >> n >> e;
		n++;
		vector< pair<int, int> > graph[n];

		while (e--)
		{
			int a, b, w;
			cin >> a >> b >> w;

			graph[a].push_back(make_pair(b, w));
			graph[b].push_back(make_pair(a, w));
		}

		cout << p * prim(graph, n) << "\n";
	}

	return 0;
}
