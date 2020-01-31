// https://www.spoj.com/problems/KNAPSACK/
// reference: https://en.wikipedia.org/wiki/Knapsack_problem

#include <iostream>
#include <string.h>

using namespace std;

struct item
{
	int w, v;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k, n;
	cin >> k >> n;
	item obj[n+1];
	int memo[n+1][k+1];

	for (int i=1; i<=n; i++)
	{
		cin >> obj[i].w >> obj[i].v;
	}

	for (int j=0; j<=k; j++)
	{
		memo[0][j] = 0;
	}

	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<=k; j++)
		{
			if (obj[i].w > j)
			{
				memo[i][j] = memo[i-1][j];
			}

			else
			{
				memo[i][j] = max(memo[i-1][j], obj[i].v + memo[i-1][j-obj[i].w]);
			}
		}
	}

	cout << memo[n][k] << "\n";

	return 0;
}
