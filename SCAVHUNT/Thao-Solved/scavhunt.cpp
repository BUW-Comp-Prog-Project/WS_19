// https://www.spoj.com/problems/SCAVHUNT/

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool visited[333];
stack<int> steps;

void dfs(int routes[], int n)
{
	visited[n] = true;

	int next = routes[n];

	if (!visited[next] && next != -1)
	{
		dfs(routes, next);
	}

	steps.push(n);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases, n, e;
	string a, b;
	cin >> cases;

	for (int c=1; c<=cases; c++)
	{
		cin >> n;
		e = n - 1;

		unordered_map<string, int> poi;
		string lookup[n];
		int routes[n];
		int counter = 0;

		for (int i=0; i<n; i++)
		{
			visited[i] = false;
			routes[i] = -1;

		}

		for (int i=0; i<e; i++)
		{
			cin >> a >> b;

			if (poi.find(a) == poi.end())
			{
				lookup[counter] = a;
				poi[a] = counter++;
			}

			if (poi.find(b) == poi.end())
			{
				lookup[counter] = b;
				poi[b] = counter++;
			}

			routes[poi[a]] = poi[b];
		}

		for (int i=0; i<n; i++)
		{
			if (!visited[i])
			{
				dfs(routes, i);
			}
		}

		cout << "Scenario #" << c << ":" << "\n";

		while (!steps.empty())
		{
			cout << lookup[steps.top()] << "\n";
			steps.pop();
		}

		cout << "\n";
	}

	return 0;
}
