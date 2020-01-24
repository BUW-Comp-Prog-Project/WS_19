// https://www.spoj.com/problems/NOCHANGE/

#include <iostream>

using namespace std;

int v[5];
bool mem[100001];

void subtract(int n, int current)
{
	for (int i=0; i<n; i++)
	{
		int rem = current - v[i];

		if (rem < 0 || mem[0]) break;

		if (mem[rem]) continue;

		mem[rem] = true;
		subtract(n, rem);
	}
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int total, n;
	cin >> total >> n;
	string ans = "NO";

	cin >> v[0];
	mem[0] = false;

	for (int i=1; i<n; i++)
	{
		cin >> v[i];
		v[i] += v[i-1];
		mem[i] = false;
	}

	subtract(n, total);

	if (mem[0] || total == 0)
	{
		ans = "YES";
	}

	cout << ans << "\n";

	return 0;
}
