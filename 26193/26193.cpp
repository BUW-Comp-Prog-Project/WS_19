#include <unordered_map>
#include <iostream>
using namespace std;
unordered_map<string, int>disjointForest;
int parent[200002];

void createElement(int v)
{
	parent[v] = -1;
}

int unionFind(int x, int y, bool u)
{
	int i = x, j = y, t;
	while (parent[i] >= 0) { i = parent[i];}
	while (parent[j] >= 0) { j = parent[j];}
	while (parent[x] >= 0) { t = x; x = parent[x]; parent[t] = i; }
	while (parent[y] >= 0) { t = y; y = parent[y]; parent[t] = j; }
	if (u && i != j)
	{
		if(parent[j] < parent[i])
		{
			parent[j] += parent[i]; parent[i] = j;
			return parent[j]*-1;
		}
		else
		{
			parent[i] += parent[j]; parent[j] = i;
			return parent[i]*-1;
		}
	}
	return parent[i]*-1;

}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int sz = 2 * n;
		for (size_t i = 1; i < sz + 3; i++)
		{
			createElement(i);
		}

		int counter = 1;
		while (n--)
		{
			string a, b;
			cin >> a >> b;
			if (disjointForest[a] == 0)
			{
				disjointForest[a] = counter;
				counter++;
			}
			if (disjointForest[b] == 0)
			{
				disjointForest[b] = counter;
				counter++;
			}
			cout << unionFind(disjointForest[a], disjointForest[b], true) << endl;;

		}
		disjointForest.clear();
	}
	return 0;
}