// https://www.spoj.com/problems/FOXLINGS/

//#include <bits/stdc++.h>
#include <iostream>
#include <map>

#define ui unsigned int

using namespace std;

map<ui, ui> foxes;

int find_root(ui i)
{
	while (foxes[i] > 0)
	{
		i = foxes[i];
	}

	return i;
}

void union_find(ui i, ui j) // i and j here are already the root nodes
{
	if (i < j)
	{
		foxes[j] = i;
	}

	else
	{
		foxes[i] = j;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ui n, m, crackers;

	cin >> n >> m;

	crackers = n;

	while (m > 0)
	{
		ui a, b;

		cin >> a >> b;

		ui root_a = find_root(a);
		ui root_b = find_root(b);

		if (foxes.find(a) == foxes.end() && foxes.find(b) == foxes.end())
		{
			foxes[a] = 0;
			foxes[b] = a;
			--crackers;
		}

		else if (foxes.find(a) != foxes.end() && foxes.find(b) == foxes.end())
		{
			foxes[b] = root_a;
			--crackers;
		}

		else if (foxes.find(a) == foxes.end() && foxes.find(b) != foxes.end())
		{
			foxes[a] = root_b;
			--crackers;
		}

		else if (root_a != root_b)
		{
			union_find(root_a, root_b);
			--crackers;
		}

		--m;

	}

	cout << crackers << "\n";

	return 0;
}
