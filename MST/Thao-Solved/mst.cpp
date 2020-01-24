// https://www.spoj.com/problems/MST/

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

vector< pair<ll, ll> > graph[10010];
ll mst = 0;

void prim(int n)
{
	priority_queue< pair<ll, ll> > q;
	bool visited[n+1];
	memset(visited, false, sizeof(visited));
	q.push(make_pair(0, 1));

	while (!q.empty())
	{
		ll a = q.top().second;
		ll w = q.top().first;
		q.pop();

		if (visited[a]) continue;

		visited[a] = true;
		mst -= w;

		for (auto next: graph[a])
		{
			ll b = next.first;
			ll w = next.second;
			q.push(make_pair(-w, b));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, e;
	cin >> n >> e;

	while (e--)
	{
		ll a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back(make_pair(b, w));
		graph[b].push_back(make_pair(a, w));
	}

	prim(n);

	cout << mst << "\n";

	return 0;
}
