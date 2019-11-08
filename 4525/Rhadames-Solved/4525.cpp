#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#include <string.h>
#include <iostream>
#include <string>

// by rhadames carmona

using namespace std;

char a[8][8];
bool b[8][8];
int s; //size of the input matrix

struct coord // i<=j
{
	coord()
	{
		i = j = -1; //empty
	}

	~coord()
	{
	}

	coord(int i, int j)
	{
		this->i = i;
		this->j = j;
	}

	bool operator < (const coord& s) const
	{
		return (i < s.i || (i == s.i && j < s.j));
	}

	bool operator > (const coord& s) const
	{
		return (i > s.i || (i == s.i && j > s.j));
	}

	int i, j;
};

struct seq: public set<coord>
{
	seq()
	{

	}

	seq(const seq& q)
	{
		*this = q;
	}

	bool operator < (const seq& q) const
	{
		for (set< coord>::iterator i = begin(); i != end(); )
		{
			for (set< coord>::iterator j = q.begin(); j != q.end(); )
			{
				if (i == end())
				{
					if (j == q.end())
						return false;
					return true;
				}
				else
				{
					if (j == q.end())
						return false;
					if (*i < *j)
						return true;
					if (*i > * j)
						return false;
					i++; j++;
				}

			}
		}
		return false;
	}
};

// solutions
set<seq> sol;

void bt(int i, int j, seq& se)
{
	if (se.size() == 8)
	{
		// unique solutions.... 
		sol.insert(se);
		return;
	}
	coord cand[4] = { coord(i - 1, j), coord(i + 1, j), coord(i,j - 1), coord(i,j + 1) };
	for (int c = 0; c < 4; c++)
	{
		int I = cand[c].i;
		int J = cand[c].j;
		if (I>=0 && J>=0 && I<s && J<s && b[I][J] == false && (a[I][J] == 'x' || a[I][J] == 'X'))
		{
			b[I][J] = true;	se.insert(coord(I, J));
			bt(I, J, se);
			b[I][J] = false;se.erase(coord(I, J));
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
		cin >> s;
		string line;
		getline(std::cin, line);
		for (int i = 0; i < s; i++)
		{
			getline(std::cin, line);
			for (int j = 0; j < s; j++)
				a[i][j] = line[j];
		}
		sol.clear();
		for (int i = 0; i < s; i++) for (int j = 0; j < s; j++)
		{
			if (a[i][j] == 'X' || a[i][j] == 'x')
			{
				seq se;
				se.insert(coord(i, j));
				memset(b, false, sizeof(bool) * 8 * s);
				b[i][j] = true;
				bt(i, j, se);
			}
		}
		cout << sol.size() << endl;
	}

	return 0;
}