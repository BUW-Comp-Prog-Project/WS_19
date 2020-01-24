// http://www.spoj.com/problems/PT07Z/

#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[10010];
int farthest_place;
int max_distance;

void dfs(int current_place, int previous_place, int previous_distance)
{
	for (auto next_place: graph[current_place])
	{
		if (next_place != previous_place)
		{
			int current_distance = previous_distance + 1;

			if (max_distance < current_distance)
			{
				max_distance = current_distance;
				farthest_place = next_place;
			}

			dfs(next_place, current_place, current_distance);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int e = n - 1;

	while (e--)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, 0, 0);
	dfs(farthest_place, 0, 0);
	cout << max_distance << "\n";

	return 0;
}
