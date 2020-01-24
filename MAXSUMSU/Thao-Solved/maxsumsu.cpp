#include <iostream>
#include <string.h>
#include <limits>
#define ll long long

using namespace std;

ll inf = numeric_limits<long int>::min();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll cases;
	cin >> cases;

	while (cases--)
	{
		ll n;
		cin >> n;
		ll seq[n], mem[n];
		ll max_sum = inf;

		mem[0] = 0;

		for (ll i=0; i<n; i++)
		{
			cin >> seq[i];

			if (i == 0)
			{
				mem[i] = seq[i];
			}

			else
			{
				mem[i] = max(seq[i], seq[i] + mem[i-1]);
			}

			if (max_sum < mem[i])
			{
				max_sum = mem[i];
			}
		}

		cout << max_sum << "\n";
	}

	return 0;
}
