
#include <vector>
#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;
int n, q;
vector <int> v;
// size of connected component * hash of root nodes with that size
map <int, unordered_set<int>> m;

void unionfind(int x, int y) {  // with path comp.
	int i = x, j = y, t;
	while (v[i] > 0) i = v[i]; // find root of x
	while (v[j] > 0) j = v[j]; // find root of y
	while (v[x] > 0) { t = x; x = v[x]; v[t] = i; }  // path c.
	while (v[y] > 0) { t = y; y = v[y]; v[t] = j; }  // path c.
	if (i != j) 
	{
		if (v[j] < v[i])   // more negative-->larger 
		{
			m[-v[j]].erase(j); if (m[-v[j]].size() == 0) m.erase(-v[j]);
			v[j] += v[i] - 1; 
			m[-v[j]].insert(j);

			m[-v[i]].erase(i); if (m[-v[i]].size() == 0) m.erase(-v[i]);
			v[i] = j;
		}
		else
		{
			m[-v[i]].erase(i); if (m[-v[i]].size() == 0) m.erase(-v[i]);
			v[i] += v[j] - 1;
			m[-v[i]].insert(i);
			m[-v[j]].erase(j); if (m[-v[j]].size() == 0) m.erase(-v[j]);
			v[j] = i;
		}
	}
}


int main()
{
	cin >> n >> q;
	v.resize(n+1);
	v[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		v[i] = 0;
		m[0].insert(i);
	}
	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		unionfind(x, y);
		int lastResult = m.rbegin()->first - m.begin()->first;
		cout << lastResult << endl;
	}

	return 0;
}