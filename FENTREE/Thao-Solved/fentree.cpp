// https://www.spoj.com/problems/FENTREE/
// reference: https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/

#include <iostream>

#define ll long long

using namespace std;

ll get_sum(ll fentree[], int i)
{
	ll sum = 0;

	while (i > 0)
	{
		sum += fentree[i];
		i -= i & (-i);
	}

	return sum;
}

void update_tree(ll fentree[], int n, int i, ll v)
{
	i++;

	while (i <= n)
	{
		cout << "i: " << i << "\n";
		fentree[i] += v;
		i += i & (-i);
	}
}

ll *build_tree(ll arr[], int n)
{
	ll *fentree = new ll[n+1];

	for (int i=1; i<=n; i++)
	{
		fentree[i] = 0;
	}

	for (int i=0; i<n; i++)
	{
		update_tree(fentree, n, i, arr[i]);
	}

	return fentree;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n;
	ll arr[n];

	for (int i=0; i<n; i++)
	{
		cin >> arr[i];
	}

	ll *fentree = build_tree(arr, n);

	cin >> q;

	while (q > 0)
	{
		string op;
		ll l, r, i, x;

		cin >> op;

		if (op == "q")
		{
			cin >> l >> r;
			l--;
			cout << get_sum(fentree, r) - get_sum(fentree, l) << "\n";
		}

		else if (op == "u")
		{
			cin >> i >> x;
			i--;
			update_tree(fentree, n, i, x);
		}

		for (int j=1; j<=n; j++)
		{
			cout << fentree[j] << " ";
		}

		cout << "\n";
		q--;
	}

	return 0;
}
