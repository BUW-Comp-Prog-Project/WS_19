// https://www.spoj.com/problems/SANTA1/

#include <iostream>
#include <map>
#include <set>

using namespace std;

class Reindeer {
public:
	unsigned long s; // seniority
	unsigned long p; // productivity

	Reindeer()
	{
		s = 0;
		p = 0;
	}

	Reindeer(unsigned long s, unsigned long p)
	{
		this->s = s;
		this->p = p;
	}

	// Reindeers are compared based on their seniority and productivity, respectively.
	bool operator < (const Reindeer& r) const
	{
		return s < r.s || (s == r.s && p < r.p);
	}
};

int main()
{
	unsigned long cases, s, p, total_p;
	string op, name;
	map<string, Reindeer> reindeer_map;
	set<Reindeer> reindeer_set;

	cin >> cases;

	while (cases > 0)
	{
		cin >> op;
		cin >> name;

		if (op == "A")
		{
			cin >> s;
			cin >> p;

			Reindeer r (s, p);

			reindeer_set.insert(r);
			reindeer_map[name] = r;

			if (reindeer_set.size() <= 1)
			{
				total_p = 0;
			}

			else
			{
				auto it = reindeer_set.find(r);
				auto prev_it = --(reindeer_set.find(r));
				auto next_it = ++(reindeer_set.find(r));

				if (it == reindeer_set.begin())
				{
					total_p += (*it).p * (*next_it).p;
				}

				else if (it == prev(reindeer_set.end()))
				{
					total_p += (*it).p * (*prev_it).p;
				}

				else
				{
					total_p += (*it).p * (*next_it).p;
					total_p += (*it).p * (*prev_it).p;
					total_p -= (*prev_it).p * (*next_it).p;
				}
			}
		}

		else if (op == "R")
		{
			Reindeer temp = reindeer_map[name];

			if (reindeer_set.size() <= 2)
			{
				total_p = 0;
			}

			else
			{
				auto it = reindeer_set.find(temp);
				auto prev_it = --(reindeer_set.find(temp));
				auto next_it = ++(reindeer_set.find(temp));

				if (it == reindeer_set.begin())
				{
					total_p -= (*it).p * (*next_it).p;
				}

				else if (it == prev(reindeer_set.end()))
				{
					total_p -= (*it).p * (*prev_it).p;
				}

				else
				{
					total_p -= (*it).p * (*next_it).p;
					total_p -= (*it).p * (*prev_it).p;
					total_p += (*prev_it).p * (*next_it).p;
				}
			}

			reindeer_set.erase(temp);
		}

		cout << total_p << "\n";

		--cases;
	}

	return 0;
}
