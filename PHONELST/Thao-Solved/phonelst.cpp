// https://www.spoj.com/problems/PHONELST/

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;

	while (cases--)
	{
		int n;
		cin >> n;
		int trie[100010][10];
		memset(trie, -1, sizeof(trie));
		string ans = "YES";
		int curr, next = 0;

		while (n--)
		{
			string phone_num;
			cin >> phone_num;
			int last_digit = phone_num.size()-1;
			curr = 0;

			if (ans == "YES")
			{
				for (int i=0; i<last_digit; i++)
				{
					int temp = curr;

					if (trie[curr][phone_num[i]] == -1)
					{
						next++;
						trie[curr][phone_num[i]] = next;
						curr = next;
					}

					else if (trie[curr][phone_num[i]] > 0)
					{
						curr = trie[curr][phone_num[i]];
					}

					else
					{
						ans = "NO";
						break;
					}
				}

				if (trie[curr][phone_num[last_digit]] > 0)
				{
					ans = "NO";
				}

				else
				{
					trie[curr][phone_num[last_digit]] = -2;
				}
			}
		}

		cout << ans << "\n";
	}

	return 0;
}
