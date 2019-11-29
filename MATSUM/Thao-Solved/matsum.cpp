// https://www.spoj.com/problems/MATSUM/
// reference: https://www.geeksforgeeks.org/pass-2d-array-parameter-c/

#include <iostream>

using namespace std;

int get_sum(int *fenwick_tree, int n, int i, int j)
{
	int sum = 0;
	i++;
	j++;

	int temp_j = j;

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

	int temp_j = j;

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
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;

	while (cases > 0)
	{
		int n; // size of the matrix
		string op = ""; // operation
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
				int x, y, num;
				cin >> x >> y >> num;
				update_tree((int *) fenwick_tree, n, x, y, num - mat[x][y]);
				mat[x][y] = num;
			}

			else if (op == "SUM")
			{
				int x1, y1, x2, y2;
				cin >> x1 >> y1 >> x2 >> y2;
				x1--;
				y1--;
				int sum1 = get_sum((int *) fenwick_tree, n, x1, y1);
				int sum2 = get_sum((int *) fenwick_tree, n, x1, y2);
				int sum3 = get_sum((int *) fenwick_tree, n, x2, y1);
				int sum4 = get_sum((int *) fenwick_tree, n, x2, y2);
				cout << sum4 - sum3 - sum2 + sum1 << "\n";
			}

			// debugging
//			for (int i=1; i<n; i++)
//			{
//				for (int j=1; j<n; j++)
//				{
//					cout << fenwick_tree[i][j] << " ";
//				}

//				cout << "\n";
//			}
		}

		cout << "\n";

		--cases;
	}

	return 0;
}
