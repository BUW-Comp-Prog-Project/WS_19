// https://www.spoj.com/problems/DBALLZ/
// reference: https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/

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

	int cases;
	cin >> cases;

	while (cases--)
	{
		int k, n;
		cin >> k >> n;
		item obj[n];
		int memo[k+1];
		memset(memo, 0, sizeof(memo));

		for (int i=0; i<n; i++)
		{
			cin >> obj[i].w;
		}

		for (int i=0; i<n; i++)
		{
			cin >> obj[i].v;
		}

		for (int i=0; i<=k; i++)
		{
			for (int j=0; j<n; j++)
			{
				if (obj[j].w <= i)
				{
					memo[i] = max(memo[i], obj[j].v + memo[i-obj[j].w]);
				}
			}
		}

		cout << memo[k] << "\n";
	}

	return 0;
}
