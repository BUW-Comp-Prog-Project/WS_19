// https://www.spoj.com/problems/SOCNETC/

#include <iostream>

using namespace std;

int friends[100000];

int find_root(int i)
{
	while (friends[i] > 0)
	{
		i = friends[i];
	}

	return i;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, q;

	cin >> n >> m >> q;

	for (int i=1; i<=n; i++)
	{
		friends[i] = -1;
	}

	while (q > 0)
	{
		string op; // type of request
		int x, y;

		cin >> op >> x;

		int root_x = find_root(x);

		if (op == "A")
		{
			cin >> y;
			int root_y = find_root(y);
			int merge = -1 * (friends[root_x] + friends[root_y]);

			if (merge <= m && root_x != root_y)
			{
				if (friends[root_x] < friends[root_y])
				{
					friends[root_x] += friends[root_y];
					friends[y] = root_x;
					friends[root_y] = root_x;
				}

				else
				{
					friends[root_y] += friends[root_x];
					friends[x] = root_y;
					friends[root_x] = root_y;
				}	
			}
		}

		else if (op == "E")
		{
			cin >> y;
			int root_y = find_root(y);

			if (root_x == root_y)
			{
				cout << "Yes" << "\n";
			}

			else
			{
				cout << "No" << "\n";
			}
		}

		else if (op == "S")
		{
			cout << -friends[root_x] << "\n";
		}

		--q;
		
	}

	return 0;
}
