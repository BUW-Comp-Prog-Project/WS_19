#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,char> > entry;
    vector<int> solutions;

    int i, n, k, l, tmp, max;
    cin >> n;

    while(n--)
    {
        tmp = 0;
        max = 0;
        entry.clear();
        cin >> k;
        for (i = 0; i < 2*k; i++)
        {
            cin >> l;
            (i%2 == 0) ? entry.push_back(make_pair(l, 'e')) : entry.push_back(make_pair(l, 'l'));
        }

        sort(entry.begin(), entry.end());

        for (i = 0; i < 2*k; i++)
        {
            (entry[i].second == 'e') ? tmp++ : tmp--;

            if(tmp > max)
                max = tmp;
        }
        solutions.push_back(max);
    }

    for(i = 0; i < solutions.size(); i++)
    {
        cout << solutions[i] << endl;
    }

    return 0;
}