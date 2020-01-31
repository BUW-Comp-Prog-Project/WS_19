// https://www.spoj.com/problems/MATSUM/
// reference: https://www.geeksforgeeks.org/pass-2d-array-parameter-c/

#include <iostream>

using namespace std;

int sum, temp_j, n, cases, x, y, num, x1, y1, x2, y2, sum1, sum2, sum3, sum4;
string op;

int get_sum(int *fenwick_tree, int n, int i, int j)
{
	sum = 0;
	i++;
	j++;

	temp_j = j;

	while (i > 0)
	{
		j = temp_j;

		while (j > 0)
		{
			sum += *((fenwick_tree + i * n) + j);
			j -= j & (-j);
		}

		i -= i & (-i);
	}

	return sum;
}

void update_tree(int *fenwick_tree, int n, int i, int j, int v)
{
	i++;
	j++;

	temp_j = j;

	while (i < n)
	{
		j = temp_j;

		while (j < n)
		{
			*((fenwick_tree + i * n) + j) += v;
			j += j & (-j);
		}

		i += i & (-i);
	}
}

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> cases;

	while (cases > 0)
	{
		op = ""; // operation
		cin >> n;

		n++;

		int mat[n][n];
		int fenwick_tree[n][n];

		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				mat[i][j] = 0;
				fenwick_tree[i][j] = 0;
			}
		}

		while (op != "END")
		{
			cin >> op;

			if (op == "SET")
			{
				cin >> x >> y >> num;
				update_tree((int *) fenwick_tree, n, x, y, num - mat[x][y]);
				mat[x][y] = num;
			}

			else if (op == "SUM")
			{
				cin >> x1 >> y1 >> x2 >> y2;
				x1--;
				y1--;
				sum1 = get_sum((int *) fenwick_tree, n, x1, y1);
				sum2 = get_sum((int *) fenwick_tree, n, x1, y2);
				sum3 = get_sum((int *) fenwick_tree, n, x2, y1);
				sum4 = get_sum((int *) fenwick_tree, n, x2, y2);
				cout << sum4 - sum3 - sum2 + sum1 << "\n";
			}
		}

		cout << "\n";

		--cases;
	}

	return 0;
}