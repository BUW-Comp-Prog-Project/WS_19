// https://www.spoj.com/problems/BUGLIFE/

#include <iostream>
#include <vector>
#define ul unsigned long
#define max 2001

using namespace std;

int color[max];
bool gay_bug_found = false;

void identify_bug(int bug, vector<int> bugs[])
{
	for (auto partner: bugs[bug])
	{
		if (color[partner] == -1)
		{
			color[partner] = 1 - color[bug];
			identify_bug(partner, bugs);
		}

		else if (color[partner] != 1 - color[bug])
		{
			gay_bug_found = true;
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;

	for (int c=1; c<=cases; c++)
	{
		int n, x, y;
		ul in;
		cin >> n >> in;
		vector<int> bugs[n+1];
		gay_bug_found = false;

		for (int i=1; i<=n; i++)
		{
			color[i] = -1;
		}

		while (in--)
		{
			cin >> x >> y;
			bugs[x].push_back(y);
			bugs[y].push_back(x);
		}

		for (int i=1; i<=n; i++)
		{
			if (gay_bug_found)
			{
				break;
			}

			if (color[i] == -1)
			{
				color[i] = 0;
			}

			identify_bug(i, bugs);
		}

		cout << "Scenario #" << c << ":" << "\n";

		if (gay_bug_found)
		{
			cout << "Suspicious bugs found!" << "\n";
		}

		else
		{
			cout << "No suspicious bugs found!" << "\n";
		}

//		for (int i=1; i<=n; i++)
//		{
//			cout << color[i] << "\n";
//		}
	}

	return 0;
}
