// https://www.spoj.com/problems/CAPCITY/

#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

struct node {
	vector<int> neighbors;
	int visited;
};

node graph[100010];
node r_graph[100010];
stack<int> sorted;
set<int> capitals;
int scc = 0;

//vector<int> graph[100010];
//int visited[100010];
//vector<int> r_graph[100010];
//int visited2[100010];

void dfs(int current)
{
	if (graph[current].visited != 0) return;

	graph[current].visited = 1;

	for (auto next: graph[current].neighbors)
	{
		dfs(next);
	}

	sorted.push(current);
}

void dfs2(int current)
{
	r_graph[current].visited = scc;

	for (auto next: r_graph[current].neighbors)
	{
		if (r_graph[next].visited == 0)
		{
			dfs2(next);
			capitals.insert(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, e, a, b;
	cin >> n >> e;

	for (int i=1; i<=n; i++)
	{
		graph[i].visited = 0;
		r_graph[i].visited = 0;
	}

	while (e--)
	{
		cin >> a >> b;
		graph[a].neighbors.push_back(b);
		r_graph[b].neighbors.push_back(a);
	}

	for (int i=1; i<=n; i++)
	{
		dfs(i);
	}

	while (!sorted.empty())
	{
		int x = sorted.top();
		scc++;

		if (r_graph[x].visited == 0)
		{
			capitals.clear();
			capitals.insert(x);
			dfs2(x);
		}

		sorted.pop();
	}

	cout << capitals.size() << "\n";

	for (auto it=capitals.begin(); it!=capitals.end(); it++)
	{
		cout << *it << " ";
	}

	cout << "\n";

	return 0;
}
