// https://www.spoj.com/problems/TULIPNUM/

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;

	for (int c=1; c<=cases; c++)
	{
		int n, q, x, y;
		cin >> n >> q;

		int prev, current;
		cin >> prev;

		int tulip[n];
		tulip[0] = 1;

		for (int i=1; i<n; i++)
		{
			cin >> current;
			if (current != prev)
			{
				tulip[i] = tulip[i-1] + 1;
			}

			else
			{
				tulip[i] = tulip[i-1];
			}

			prev = current;
		}

		cout << "Case " << c << ":" << "\n";

		while (q--)
		{
			cin >> x >> y;
			cout << tulip[y-1] - tulip[x-1] + 1 << "\n";
		}
	}

	return 0;
}
