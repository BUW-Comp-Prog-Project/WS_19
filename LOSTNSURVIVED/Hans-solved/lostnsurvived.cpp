#include <unordered_map>
#include <iostream>
#include <set>

using namespace std;
int parent[200002];
multiset<int> s;

void createElement(int v)
{
	parent[v] = -1;
    s.insert(1);
}

int find(int x)
{
    while (parent[x] >= 0) { x = parent[x];}
    return x;
}

bool unionFind(int x, int y, bool u)
{
	int i = x, j = y, t;
    i = find(i);
    j = find(j);
	while (parent[x] >= 0) { t = x; x = parent[x]; parent[t] = i; }
	while (parent[y] >= 0) { t = y; y = parent[y]; parent[t] = j; }
	if (u && i != j)
	{
        s.erase(s.find(parent[j]*-1));
        s.erase(s.find(parent[i]*-1));

        if(parent[j] < parent[i])
        {
            parent[j] += parent[i]; parent[i] = j;
            s.insert(parent[j]*-1);
            return true;
        }
        else
        {
            parent[i] += parent[j]; parent[j] = i;
            s.insert(parent[i]*-1);
            return true;
        }
	}
	return false;
}

int main()
{
	int n, q;
	cin >> n;
    cin >> q;

    for (size_t i = 1; i <= n ; i++)
    {
        createElement(i);
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        unionFind(a, b, true);
        cout << *--s.end() - *s.begin() << endl;
    }
	return 0;
}
