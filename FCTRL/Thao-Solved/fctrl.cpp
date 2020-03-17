// https://www.spoj.com/problems/FCTRL/

#include <iostream>
#include <math.h>

using namespace std;

int count_zeros(int n)
{
	int zeros = 0;

	for (int i=1; pow(5, i) <= n; i++)
	{
		zeros += floor(n / pow(5, i));
	}

	return zeros;
}

int main()
{	
	int t, n;
	cin >> t;

	while (t>0)
	{
		cin >> n;
		cout << count_zeros(n) << "\n";
		--t;
	}

	return 0;
}
