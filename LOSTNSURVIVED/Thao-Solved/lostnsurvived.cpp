// https://www.spoj.com/problems/LOSTNSURVIVED/

#include <iostream>
#include <set>

using namespace std;

int survivors[100001];
multiset<int> group_size;

int find_root(int i)
{
	while (survivors[i] > 0)
	{
		i = survivors[i];
	}

	return i;
}

int main()
{
	int n; // number of survivors
	int q; // number of lines

	cin >> n >> q;

	// Initially, everyone is in their own group, so we have n groups of size 1.
	for (int i=1; i<=n; i++)
	{
		survivors[i] = -1;
		group_size.insert(-1);
	}

	int total = 0;

	while (q > 0)
	{
		int a, b;

		cin >> a >> b;

		int root_a = find_root(a);
		int root_b = find_root(b);

		if (root_a != root_b)
		{
			group_size.erase(group_size.find(survivors[root_a]));
			group_size.erase(group_size.find(survivors[root_b]));

			// If a is in a larger group, then b joins a.
			if (survivors[root_a] < survivors[root_b])
			{
				survivors[root_a] += survivors[root_b];
				group_size.insert(survivors[root_a]);
				survivors[b] = root_a;
				survivors[root_b] = root_a;
			}

			else
			{
				survivors[root_b] += survivors[root_a];
				group_size.insert(survivors[root_b]);
				survivors[a] = root_b;
				survivors[root_a] = root_b;
			}
		}

		int largest = -*group_size.begin();
		int smallest = -*prev(group_size.end());

		int diff = largest - smallest;

		cout << diff << "\n";

		--q;
	}

	return 0;
}
