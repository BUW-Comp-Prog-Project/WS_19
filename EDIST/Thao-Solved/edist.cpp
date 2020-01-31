// https://www.spoj.com/problems/EDIST/

#include <iostream>
#include <string.h>

using namespace std;

string a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;

	while (cases--)
	{
		cin >> a >> b;
		int m = a.size() + 1;
		int n = b.size() + 1;
		int memo[2][n];
		bool odd;

		for (int j=0; j<n; j++)
		{
			memo[0][j] = j;
		}

		for (int i=1; i<m; i++)
		{
			odd = i%2;
			memo[odd][0] = i;

			for (int j=1; j<n; j++)
			{
				memo[odd][j] = (a[i-1] == b[j-1]) ? (memo[!odd][j-1]) : (1 + min(min(memo[!odd][j], memo[odd][j-1]), memo[!odd][j-1]));
			}
		}

		cout << memo[odd][n-1] << "\n";
	}

	return 0;
}
