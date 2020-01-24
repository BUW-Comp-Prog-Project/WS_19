// https://www.spoj.com/problems/MAXSUMSQ/

#include <iostream>
#include <string.h>
#define ll long long

using namespace std;

ll seq[100010], memo[100010];
ll max_sum, count_max, count_zeros;

void get_sum(ll n)
{
	for (ll i=0; i<n; i++)
	{
		memo[i] = max(seq[i], memo[i-1] + seq[i]);

		if (max_sum < memo[i])
		{
			count_max = 1;
			count_max += count_zeros;
			max_sum = memo[i];
		}

		else if (max_sum == memo[i])
		{
			count_max++;
			count_max += count_zeros;
		}

		if (memo[i] == 0)
		{
			count_zeros++;
		}

		else if (memo[i] < 0)
		{
			count_zeros = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;

	while (cases--)
	{
		ll n;
		max_sum = -10000, count_max = 1, count_zeros = 0;

		cin >> n;

		for (ll i=0; i<n; i++)
		{
			cin >> seq[i];
			memo[i] = 0;
		}

		get_sum(n);

		cout << max_sum << " " << count_max << "\n";
	}

	return 0;
}
