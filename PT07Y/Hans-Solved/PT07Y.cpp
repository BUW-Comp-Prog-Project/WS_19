#include <vector>
#include <iostream>

using namespace std;

typedef vector<vector<int>> graph;

vector<int> visited;
bool loop = false;

void visit(graph& g, int k) {
	visited[k] = 1;
	for (auto el : g[k])
	{
		if (visited[el] == -1)
			visit(g, el);
		else {
			loop = true;
		}
	}
	return;
}
bool findCycles(graph& g) {
	for (int i = 0; i < g.size(); i++)
	{
		if (visited[i] == -1)
		{
			visit(g, i);
			if(loop == true)
				return true;
		}
	}
	return false;
}

int main()
{
	graph g;
	vector<int> tmp;
	int n, m, x, y;
	cin >> n >> m;
	while (n--)
	{
		g.push_back(tmp);
		visited.push_back(-1);
	}

	while (m--)
	{
		cin >> x >> y;
		g[x-1].push_back(y-1);
	}
	(!findCycles(g)) ? cout << "YES" : cout << "NO";
}