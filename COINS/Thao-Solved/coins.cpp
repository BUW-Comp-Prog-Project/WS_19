// https://www.spoj.com/problems/COINS/

#include <iostream>
#include <string.h>
#include <unordered_map>
#define ull unsigned long long

using namespace std;

unordered_map<ull, ull> usd;
usd[0] = 0;

ull exchange(ull x)
{
	if (usd.find(x) == usd.end())
	{
		usd[x] = max(x, exchange(x/2) + exchange(x/3) + exchange(x/4));
	}

	return usd[x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ull n;

	while (cin >> n)
	{
		cout << exchange(n) << "\n";
	}

	return 0;
}
