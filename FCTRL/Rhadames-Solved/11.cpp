#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int zeros(int x)
{
	int c = 0, d = 5;
	while (x / d > 0)
	{
		c = c + x / d;
		d = d * 5; // powers of 5
	}
	return c;
}

int main()
{

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a;
		cin >> a;
		cout << zeros(a) << endl;
	}
	return 0;
}