#include <unordered_map>
#include <iostream>
using namespace std;
int parent[200002];
int m;

void createElement(int v)
{
	parent[v] = -1;
}

int find(int x)
{
    while (parent[x] >= 0) { x = parent[x];}
    return x;
}

bool sameParent(int x, int y)
{
    int i = x, j = y;
    bool check = false;
    i = find(i);
    j = find(j);
    (i == j) ? check = true : check = false; 
    return check;
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
        if(parent[j] + parent[i] >= - m)
        {
            if(parent[j] < parent[i])
            {
                parent[j] += parent[i]; parent[i] = j;
                return true;
            }
            else
            {
                parent[i] += parent[j]; parent[j] = i;
                return true;
            }
        }		
	}
	return false;

}

int main()
{
	int n, q;
	cin >> n;
    cin >> m;
    cin >> q;

    for (size_t i = 1; i <= n ; i++)
    {
        createElement(i);
    }

    int counter = 1;
    while (q--)
    {
        char a;
        int b, c;
        cin >> a;
        if(a == 'A')
        {
            cin >> b >> c;
            unionFind(b, c, true);
        }
        else if(a == 'E')
        {
            cin >> b >> c;
            ((sameParent(b, c))) ? cout << "Yes" << endl : cout << "No" << endl; 
        }
        else if(a == 'S')
        {
            cin >> b;
            cout << parent[find(b)]*-1 << endl;
        }
    }
	return 0;
}
