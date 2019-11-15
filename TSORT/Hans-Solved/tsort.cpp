#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int k;
    cin >> n;
    vector<int> input;

    for (int i = 0; i < n; i++)
		{
            cin >> k;
            input.push_back(k);
        }

    sort(input.begin(), input.end());

    for (int i = 0; i < n; i++)
		{
            cout << input[i] << endl;
        }
}