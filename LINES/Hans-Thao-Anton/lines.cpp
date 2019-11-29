// https://www.spoj.com/problems/LINES/

#include <iostream>
#include <set>

using namespace std;

double m(int x1, int y1, int x2, int y2)
{
	return (double) (y1 - y2) / (x1 - x2);
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
		set<double> slopes;

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
				slopes.insert(m(points[i].first, points[i].second, points[j].first, points[j].second));
			}
		}

		cout << slopes.size() << "\n";
	}

	return 0;
}
