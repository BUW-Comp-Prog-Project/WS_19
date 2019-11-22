// https://www.spoj.com/problems/FRNDCIRC/

#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> name_id;
unordered_map<int, int> id_friend;

int find_root(unordered_map<int, int>& parent, int i)
{
	while (parent[i] > 0)
	{
		i = parent[i];
	}

	return i;
}

void union_find(int i, int j)
{
	int x = find_root(id_friend, i);
	int y = find_root(id_friend, j);

	if (x != y)
	{
		if (id_friend[x] < id_friend[y])
		{
			id_friend[x] += id_friend[y];
			id_friend[y] = x;
		}

		else
		{
			id_friend[y] += id_friend[x];
			id_friend[x] = y;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	long n, counter; // number of new relations

	cin >> cases;

	while (cases > 0)
	{
		cin >> n;

		counter = 0;
		name_id.clear();
		id_friend.clear();

		while (n > 0)
		{
			string a, b;
			cin >> a >> b;

			if (name_id.find(a) == name_id.end())
			{
				name_id[a] = ++counter;
			}

			if (name_id.find(b) == name_id.end())
			{
				name_id[b] = ++counter;
			}

			int x = name_id[a];
			int y = name_id[b];

			if (id_friend.find(x) == id_friend.end() && id_friend.find(y) == id_friend.end())
			{
				id_friend[x] = -2; // two friends in the circle: root node + child node
				id_friend[y] = x;
			}

			else if (id_friend.find(x) != id_friend.end() && id_friend.find(y) == id_friend.end())
			{
				int root_node = find_root(id_friend, x);
				id_friend[y] = root_node;
				id_friend[root_node]--;
			}

			else if (id_friend.find(x) == id_friend.end() && id_friend.find(y) != id_friend.end())
			{
				int root_node = find_root(id_friend, y);
				id_friend[x] = root_node;
				id_friend[root_node]--;
			}

			else
			{
				union_find(x, y);
			}

			cout << id_friend[find_root(id_friend, x)] * (-1) << "\n";

			--n;
		}

		--cases;
	}

	return 0;
}
