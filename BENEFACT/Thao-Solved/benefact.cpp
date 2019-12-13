// https://www.spoj.com/problems/BENEFACT/

#include <iostream>
#include <vector>

using namespace std;

int max_distance = 0;
int farthest_place;

void dfs (vector< pair<int, int> > places[], int current_place, int previous_place, int previous_distance)
{
	for (auto p: places[current_place])
	{
		int next_place = p.first;

		if (next_place != previous_place)
		{
			int current_distance = previous_distance + p.second;

			if (max_distance < current_distance)
			{
				max_distance = current_distance;
				farthest_place = next_place;
			}

			dfs (places, next_place, current_place, current_distance);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;

	while (cases--)
	{
		int n, a, b, l;
		cin >> n;
		vector< pair<int, int> > places[n+1];
		int e = n - 1;
		max_distance = 0;

		while (e--)
		{
			cin >> a >> b >> l;
			places[a].push_back(make_pair(b, l));
			places[b].push_back(make_pair(a, l));
		}

		dfs(places, 1, 0, 0);
		int leaf = farthest_place;
		dfs(places, leaf, 0, 0);
		cout << max_distance << "\n";
	}

	return 0;
}
