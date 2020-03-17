#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#define N 100
using namespace std;
string f[N+1];

string sum(const string & a, const string & b)
{
	string c = b;
	while (a.size() > c.size())
		c.insert(c.begin(), '0');
	int n = a.size();
	string r;
	
	char carry = 0;
	for (int i=n-1; i>=0; i--)
	{
		char add = (a[i] - '0') + (c[i] - '0') + carry;
		if (add >= 10)
		{
			add = add - 10;
			carry = 1;
		}
		else
			carry = 0;
		r.insert(r.begin(), add + '0');
	}
	if (carry)
		r.insert(r.begin(), '1');
	return r;
}

string mult(const string& s, int x)
{
	string r = s;
	for (int i = 2; i <= x; i++)
		r = sum(r, s);
	return r;
}

void precompute()
{
	f[1] = "1";
	for (int i = 2; i <= N; i++)
	{
		f[i] = mult(f[i - 1].c_str(), i);
		//cout << i << "-->" << f[i] << "," << endl;
	}
}

int main()
{
	precompute();
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int value;
		cin >> value;
		cout << f[value] << endl;
	}
	return 0;
}