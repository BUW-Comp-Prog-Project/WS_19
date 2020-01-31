// https://www.spoj.com/problems/MIXTURES/
// reference: https://en.wikipedia.org/wiki/Matrix_chain_multiplication

#include <iostream>
#include <string.h>
#include <limits>

using namespace std;

int inf = numeric_limits<int>::max();

int mcm(int mix[], int n)
{
	int memo[n][n][2];
	int smoke;

	for (int i=1; i<n; i++)
	{
		memo[i][i][0] = 0;	// smoke
		memo[i][i][1] = mix[i];	// color
	}

	for (int len=2; len<n; len++)
	{
		for (int i=1; i<n-len+1; i++)
		{
			int j = i + len - 1;
			memo[i][j][0] = inf;

			for (int k=i; k<j; k++)
			{
				smoke = memo[i][k][0] + memo[k+1][j][0] + memo[i][k][1] * memo[k+1][j][1];

				if (smoke < memo[i][j][0])
				{
					memo[i][j][0] = smoke;
					memo[i][j][1] = (memo[i][k][1] + memo[k+1][j][1]) % 100;
				}
			}
		}
	}

	return memo[1][n-1][0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	while (cin >> n)
	{
		n++;
		int mix[n];

		for (int i=1; i<n; i++)
		{
			cin >> mix[i];
		}

		cout << mcm(mix, n) << "\n";
	}

	return 0;
}
