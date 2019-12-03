// https://www.spoj.com/problems/LINES/

#include <iostream>
#include <set>
#include <map>

using namespace std;

struct Fraction {
	int num;
	int den;

	bool operator < (const Fraction& f) const
	{
		return den < f.den || (den == f.den && num < f.num);
	}
};

Fraction reduce(Fraction f)
{
	int a = f.num;
	int b = f.den;

	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}

	int gcd = a;
	f.num = f.num / gcd;
	f.den = f.den / gcd;
	return f;
}

Fraction get_m(int x1, int y1, int x2, int y2)
{
	int dy = y1 - y2;
	int dx = x1 - x2;
	Fraction m;
	m.num = dy;
	m.den = dx;
	return reduce(m);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	for (;;)
	{
		cin >> n;
		pair<int, int> points[n];
		Fraction m;
		set<Fraction> slopes;

		if (n == 0)
		{
			break;
		}

		for (int i=0; i<n; i++)
		{
			cin >> points[i].first >> points[i].second;
		}

		for (int i=0; i<n; i++)
		{
			for (int j=i+1; j<n; j++)
			{
				m = get_m(points[i].first, points[i].second, points[j].first, points[j].second);
				slopes.insert(m);
			}
		}

		cout << slopes.size() << "\n";
	}

	return 0;
}
