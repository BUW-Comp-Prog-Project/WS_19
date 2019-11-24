// https://www.spoj.com/problems/HOMO/

#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cases, num, homo = 0, hetero = 0;
	string op, status;
	map<int, int> m; // key: the number, value: its occurence
	map<int, int>::iterator i;

	cin >> cases;

	while (cases > 0)
	{
		cin >> op;
		cin >> num;
		i = m.find(num);

		if (op == "insert")
		{
			if (i != m.end())
			{
				m[num]++;
				homo++;
			}

			else
			{
				m.insert(pair<int, int>(num, 1));
				hetero++;
			}
		}

		else if (op == "delete")
		{
			if (i != m.end())
			{
				m[num]--;
				if (m[num] == 0)
				{
					m.erase(i);
					hetero--;
				}

				else
				{
					homo--;
				}
			}
		}

		if (homo > 0 && hetero > 1)
			status = "both";
		else if (homo > 0)
			status = "homo";
		else if (hetero > 1)
			status = "hetero";
		else
			status = "neither";

		cout << status << "\n";

		--cases;
	}

	return 0;
}
