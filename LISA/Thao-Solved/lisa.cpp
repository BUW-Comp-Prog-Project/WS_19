// https://www.spoj.com/problems/LISA/

#include <iostream>
#include <string.h>
#include <limits>
#define ll long long

using namespace std;

ll p_inf = numeric_limits<long long>::max();
ll n_inf = -numeric_limits<long long>::max();

ll compute(ll x, ll y, char op)
{
	if (op == '+')	return (x + y);

	else return (x * y);
}

int mcm(string a, ll inf)
{
	int m = a.size();
	int n = m/2+2;
	ll val, memo[n][n];
	char op[n];

	for (int i=0; i<m; i++)
	{
		if (isdigit(a[i])) memo[i/2+1][i/2+1] = a[i] - '0';

		else op[i/2+1] = a[i];
	}

	for (int len=2; len<n; len++)
	{
		for (int i=1; i<n-len+1; i++)
		{
			int j = i + len - 1;
			memo[i][j] = inf;

			for (int k=i; k<j; k++)
			{
				val = compute(memo[i][k], memo[k+1][j], op[k]);
				memo[i][j] = (inf > 0) ? (min(memo[i][j], val)) : (max(memo[i][j], val));
			}
		}
	}

	return memo[1][n-1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;

	while (cases--)
	{
		string a;
		cin >> a;
		cout << mcm(a, n_inf) << " " << mcm(a, p_inf) << "\n";
	}

	return 0;
}
