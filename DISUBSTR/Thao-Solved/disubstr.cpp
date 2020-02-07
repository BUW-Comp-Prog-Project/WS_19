// https://www.spoj.com/problems/DISUBSTR/

#include <iostream>
#include <string.h>
#define max_size 1000000

using namespace std;

int trie[max_size][26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;

	while (cases--)
	{
		string x;
		cin >> x;
		int n = x.size();
		memset(trie, -1, sizeof(trie));
		int curr, next = 0;
		int num = 0;

		for (int i=0; i<n; i++)
		{
			curr = 0;

			for (int j=i; j<n; j++)
			{
				if (trie[curr][x[j]] == -1)
				{
					next++;
					trie[curr][x[j]] = next;
					curr = next;
				}

				else
				{
					curr = trie[curr][x[j]];
				}

				num = max(num, next);
			}
		}

		cout << num << "\n";
	}

	return 0;
}
