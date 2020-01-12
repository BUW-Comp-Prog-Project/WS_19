// https://www.spoj.com/problems/LINES/

#include <iostream>
#include <unordered_set>
#define max 9999

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	for (;;)
	{
		cin >> n;
		pair<double, double> points[n];
		unordered_set<double> slopes;

		if (n == 0)
		{
			break;
		}

		for (int i=0; i<n; i++)
		{
			cin >> points[i].first >> points[i].second;

			for (int j=i-1; j>=0; j--)
			{
				double m;

				if (points[i].first == points[j].first)
				{
					m = max;
				}

				else
				{
					m = (points[i].second - points[j].second) / (points[i].first - points[j].first);
				}

				slopes.insert(m);
			}
		}

		cout << slopes.size() << "\n";
	}

	return 0;
}
