#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int reverse(int x)
{
	int y = 0;
	while (x)
	{
		y = y * 10 + x % 10;
		x = x/10;
	}
	return y;
}

int main()
{

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a,b;
		cin >> a;
		cin >> b;
		a = reverse(a);
		b = reverse(b);
		int c = a + b;
		cout << reverse(c) << endl;
	}
	return 0;
}