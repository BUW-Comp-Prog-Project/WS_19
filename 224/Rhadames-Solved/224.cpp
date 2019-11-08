#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <map>
#include <string.h>

// by rhadames carmona, 0.45 seconds

using namespace std;

struct stone // i<=j
{
	stone()
	{
		i = j = -1; //empty
	}

	~stone()
	{
	}

	stone(int i, int j)
	{
		this->i = i;
		this->j = j;
	}

	bool operator < (const stone& s) const
	{
		return (i < s.i || (i == s.i && j < s.j));
	}

	int i, j;
};

// a posible stone position in the board
struct position
{
	position()
	{
	}

	~position()
	{
	}

	position(int i, int j, int k, int l)
	{
		this->i = i;
		this->j = j;
		this->k = k;
		this->l = l;
	}

	int i, j, k, l;
};


int a[7][8];
bool b[7][8];

#define pieces map <stone, vector<position>>
pieces m;

// number of combinations
int res;

// occupied cells
int busy;

void bt(pieces::iterator i)
{
	if (busy == 56)
	{
		res++;
		return;
	}

	// for each possibility of stone i
	for (int j=0; j<i->second.size(); j++)
	{
		position p = i->second[j];

		// check if the position is available
		if (!b[p.i][p.j] && !b[p.k][p.l])
		{
			// put the piece
			b[p.i][p.j] = b[p.k][p.l] = true; busy += 2;
			pieces::iterator k = i; k++;
			bt(k);
			b[p.i][p.j] = b[p.k][p.l] = false; busy -= 2;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	while (n)
	{
		--n;
		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 8; j++)
				cin >> a[i][j];
		m.clear();
		memset(b, false, sizeof(bool) * 56);

		// for each piece, get the possible positions
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int v1 = a[i][j], v2;
				if (i < 6) // we can check down
				{
					v2 = a[i + 1][j];
					stone s(min(v1, v2), max(v1, v2));
					m[s].push_back(position(i, j, i + 1, j));
				}
				if (j < 7)
				{
					v2 = a[i][j + 1];
					stone s(min(v1, v2), max(v1, v2));
					m[s].push_back(position(i, j, i, j + 1));
				}
			}
		}
		if (m.size() < 28)
			cout << 0 << endl;
		else
		{
			res = busy = 0;
			bt(m.begin());
			cout << res << endl;
		}
	}

	return 0;
}