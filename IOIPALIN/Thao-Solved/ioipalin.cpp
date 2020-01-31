// https://www.spoj.com/problems/IOIPALIN/

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int len;
	string x, rev_x;
	cin >> len >> x;
	rev_x = x;
	reverse(rev_x.begin(), rev_x.end());
	len++;
	int memo[2][len];
	bool odd;

	for (int j=0; j<len; j++)
	{
		memo[0][j] = 0;
	}

	memo[1][0] = 0;

	for (int i=1; i<len; i++)
	{
		odd = i%2;

		for (int j=1; j<len; j++)
		{
			memo[odd][j] = (x[i-1] == rev_x[j-1]) ? (1 + memo[!odd][j-1]) : (max(memo[odd][j-1], memo[!odd][j]));
		}
	}

	int longest = memo[odd][len-1];

	cout << len - longest - 1 << "\n";

	return 0;
}
