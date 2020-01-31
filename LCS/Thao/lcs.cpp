// https://www.spoj.com/problems/LCS/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> memo[2];
	string a, b;
	cin >> a >> b;
	int m = a.size(), n = b.size();
	int longest = 0;
	bool odd;

	for (int i=0; i<2; i++)
	{
		memo[i].resize(n, 0);
	}

	for (int i=1; i<m; i++)
	{
		odd = i%2;

		for (int j=1; j<n; j++)
		{
			memo[odd][j] = (a[i] == b[j]) ? (1 + memo[!odd][j-1]) : 0;
			longest = max(memo[odd][j], longest);
		}
	}

	cout << longest << "\n";

	return 0;
}
