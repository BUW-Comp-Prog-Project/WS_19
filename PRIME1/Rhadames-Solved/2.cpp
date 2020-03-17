#include <iostream>
#include <vector>
#include <cmath>

#define N 1000000000
using namespace std;
vector<int> p;

// precompute: determine the prime numbers between 3 and sqrt(n) [only odd numbers...]
void buildTable()
{
	bool prime = true;

	int top = (int)(sqrt(double(N)) + 0.5);
	// checking all odds
	for (int i = 3; i <= top; i += 2)
	{
		int n = p.size();
		prime = true;
		int m = int(sqrt(double(i))+0.5);
		for (int j = 0; j < n && p[j] <= m; j++)
		{
			if ((i % p[j]) == 0) 
			{
				prime = false;
				break;
			}
		}
		if (prime) p.push_back(i);
	}
}

bool isPrime(int x)
{
	if (x == 1) return false;
	if (x <= 3) return true;
	if (x % 2 == 0) return false;

	int n = p.size();
	bool prime = true;
	int m = int(sqrt(double(x)) + 0.5);
	for (int j = 0; j < n && p[j] <= m; j++)
	{
		if ((x % p[j]) == 0)
		{
			prime = false;
			break;
		}
	}
	return prime;
}


int main()
{
	buildTable();
	// ready for the queries
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n;
		cin >> m;
		for (int i = n; i <= m; i++) 
		{
			if (isPrime(i))
				cout << i << endl;
		}
		cout << endl; //
	}
	return 0;
}