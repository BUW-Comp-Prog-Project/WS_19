#include <vector>
#include <iostream>

using namespace std;

typedef vector<vector<int> > graph;
vector<int> best;

void visit(graph& g, int k, int end, vector<int> visited, vector<int> solution) {
	visited[k] = 1;
    solution.push_back(k);
    if(k == end)
        if(best.size() < solution.size())
            {
                best = solution;
                return;
            }
	for (auto el : g[k])
		if (visited[el] == -1)
			visit(g, el, end, visited, solution);
	}
	return;
}

int main()
{
	graph g;
	vector<int> tmp;
    vector<int> visited;
    vector<int> solution;
	
    int n, m, a, b, x, y;
	cin >> n >> m >> a >> b;
	while (n--)
	{
		g.push_back(tmp);
		visited.push_back(-1);
	}

	while (m--)
	{
		cin >> x >> y;
		g[x-1].push_back(y-1);
		g[y-1].push_back(x-1);
	}
        
	visit(g, a-1, b-1, visited, solution);

    for(auto el : best)
        cout << el + 1 << " ";
}