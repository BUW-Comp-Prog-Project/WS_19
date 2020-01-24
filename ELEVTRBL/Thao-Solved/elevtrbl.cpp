// https://www.spoj.com/problems/ELEVTRBL/

#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
bool visited[1000010];
int len[1000010];
bool use_stairs = true;

void bfs(int x, int u, int d, int f, int g)
{
	visited[x] = true;
	len[x] = 0;
	q.push(x);

	while(!q.empty())
	{
		int n = q.front();
		q.pop();

		int up = n + u;
		int down = n - d;

		if (up <= f && !visited[up])
		{
			visited[up] = true;
			len[up] = len[n] + 1;
			q.push(up);

			if (up == g)
			{
				use_stairs = false;
				return;
			}
		}

		if (down >= 1 && !visited[down])
		{
			visited[down] = true;
			len[down] = len[n] + 1;
			q.push(down);

			if (down == g)
			{
				use_stairs = false;
				return;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	for (int i=1; i<=f; i++)
	{
		visited[i] = false;
	}

	if ((s <= f) && (g <= f))
	{
		if (s == g)
		{
			use_stairs = false;
		}

		else
		{
			bfs(s, u, d, f, g);
		}
	}

	if (use_stairs)
	{
		cout << "use the stairs" << "\n";
	}

	else
	{
		cout << len[g] << "\n";
	}

	return 0;
}

