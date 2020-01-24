// http://www.spoj.com/problems/BLINNET/

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

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
		int c = q.top().first;
		q.pop();

		if (visited[a]) continue;

		visited[a] = true;
		mst -= c;

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

	int cases;
	cin >> cases;

	while (cases--)
	{
		int n, e;
		cin >> n;
		n++;
		string city;
		vector< pair<int, int> > graph[n];

		for (int i=1; i<n; i++)
		{
			cin >> city >> e;

			while (e--)
			{
				int b, w;
				cin >> b >> w;
				graph[i].push_back(make_pair(b, w));
				graph[b].push_back(make_pair(i, w));
			}
		}

		cout << prim(graph, n) << "\n";
	}

	return 0;
}
