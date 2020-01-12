// https://www.spoj.com/problems/MICEMAZE/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector< pair<int, int> > maze[110];
bool visited[110];
int escape_time[110];
priority_queue< pair<int, int> > q;
int counter = 0;
int inf = numeric_limits<int>::max();

void bfs(int x, int t)
{
	escape_time[x] = 0;
	q.push(make_pair(0, x));

	while (!q.empty())
	{
		int a = q.top().second;
		q.pop();

		if (visited[a]) continue;

		visited[a] = true;

		if (escape_time[a] <= t)
		{
			counter++;
		}

		for (auto neighbor: maze[a])
		{
			int b = neighbor.first;
			int w = neighbor.second;

			if (escape_time[a] + w < escape_time[b])
			{
				escape_time[b] = escape_time[a] + w;
				q.push(make_pair(-escape_time[b], b));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, e, t, m;
	cin >> n >> e >> t >> m;

	for (int i=1; i<=n; i++)
	{
		visited[i] = false;
		escape_time[i] = inf;
	}

	while (m--)
	{
		int a, b, w;
		cin >> b >> a >> w;

		maze[a].push_back(make_pair(b, w));
	}

	bfs(e, t);

	cout << counter << "\n";

	return 0;
}
