// https://www.spoj.com/problems/PT07Y/

#include <iostream>
#include <vector>

using namespace std;

vector<int> all_nodes[10010];
bool visited[10010];
int counter = 0;

void dfs(int node)
{
	if (visited[node])
	{
		return;
	}

	visited[node] = true;
	counter ++;

	for (auto neighbor: all_nodes[node])
	{
		dfs(neighbor);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, e; // number of nodes and edges
	cin >> n >> e;
	string is_a_tree = "YES";

	for (int i=1; i<=n; i++)
	{
		visited[i] = false;
	}

	for (int i=0; i<e; i++)
	{
		int u, v;
		cin >> u >> v;
		all_nodes[u].push_back(v);
		all_nodes[v].push_back(u);
	}

	if (n != e + 1)
	{
		is_a_tree = "NO";
	}

	else
	{
		dfs(1);

		if (counter != n)
		{
			is_a_tree = "NO";
		}
	}

	cout << is_a_tree << "\n";

	return 0;
} 
