// https://www.spoj.com/problems/BTCK/
// reference: http://www.cplusplus.com/reference/algorithm/next_permutation/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; // number of test cases
	cin >> t;

	int size = 10;

	while (t--)
	{
		int a[size], n[size], k, sum;

		for (int i=0; i<size; i++)
		{
			a[i] = i;
			cin >> n[i];
		}

		cin >> k;

		do {
			sum = 0;

			for (int i=0; i<size; i++)
			{
				sum += a[i] * n[i];
			}

			if (sum <= k)
			{
				break;
			}
		} while (next_permutation(a, a + size));

		if (sum <= k)
		{
			for (int i=0; i<size-1; i++)
			{
				cout << a[i] << " ";
			}

			cout << a[size-1] << "\n";
		}

		else
		{
			cout << -1 << "\n";
		}
	}

	return 0;
}
