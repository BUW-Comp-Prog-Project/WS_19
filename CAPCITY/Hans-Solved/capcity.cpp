#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

typedef vector<vector<int>> graph;


stack<int> s;
int counter;
vector<int> visited;
int sizes[100000];

void visit1(graph& g, int k)
{
	visited[k] = 1;
	for (auto el : g[k])
		if (visited[k] == -1)
			visit1(g, el);
    
    cout << "In Stack: " << k << ". ";
	s.push(k);
}

void visit2(graph& r, int k)
{
	visited[k] = counter;
	sizes[counter]++;
	for (auto el : r[k])
		if (visited[el] == -1)
			visit2(r, el);
	return;
}

void DFS1(graph& g)
{
	for (int i = 0; i < g.size(); i++)
		visit1(g, i);
	return;
}

void DFS2(graph& r)
{
	counter = 0;
	for (int i = 0; i < r.size(); i++)
		visited[i] = -1;
	while (!s.empty())
	{
		int x = s.top();
		if (visited[x] == -1) visit2(r, x);
		s.pop();
		counter++;
	}
}


int main()
{
	graph g;
	graph r;
	vector<int> tmp;
	int n, m, x, y;
	cin >> n >> m;
	
	while (n--)
	{
		g.push_back(tmp);
		r.push_back(tmp);
		visited.push_back(-1);
	}

	while (m--)
	{
		cin >> x >> y;
		g[x - 1].push_back(y - 1);
		r[y - 1].push_back(x - 1);
	}

	DFS1(g);
	DFS2(r);

	//auto biggest = max_element(begin(visited), end(visited));
	//for (int i = 0; i < visited.size(); i++)
	//	if (visited[i] == *biggest)
	//		tmp.push_back(i);
	//cout << tmp.size() << endl;
	//for (auto el : tmp)
	//	cout << el + 1 << " ";

    for (int i = 0; i < visited.size(); i++)
    {
        cout << endl << "Node " << i << ": ";
        for(auto j : g[i])
            cout << j +1 << " ";
    }
        
    cout << endl;

	for (int i = 0; i < visited.size(); i++)
		if (sizes[visited[i]] > 1)
			tmp.push_back(i);
    
	cout << tmp.size() << endl;
	for (auto el : tmp)
		cout << el + 1 << " ";
}