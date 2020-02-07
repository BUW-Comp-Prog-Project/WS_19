// https://www.spoj.com/problems/ADAINDEX/

#include <iostream>
#include <string.h>

using namespace std;

int trie[1000010][26];
int counter[1000010][26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;
	memset(trie, -1, sizeof(trie));
	memset(counter, 0, sizeof(counter));
	int curr, next = 0;

	while (n--)
	{
		string x;
		cin >> x;
		int s = x.size();
		curr = 0;

		for (int i=0; i<s; i++)
		{
			counter[curr][x[i]] += 1;

			if (trie[curr][x[i]] == -1)
			{
				next++;
				trie[curr][x[i]] = next;
				curr = next;
			}

			else
			{
				curr = trie[curr][x[i]];
			}
		}
	}

	while (q--)
	{
		int num = 0;
		string x;
		cin >> x;
		int s = x.size();
		curr = 0;

		for (int i=0; i<s; i++)
		{
			num = counter[curr][x[i]];
			curr = trie[curr][x[i]];
		}

		cout << num << "\n";
	}

	return 0;
}
