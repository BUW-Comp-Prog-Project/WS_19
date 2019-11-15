#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		map<string,int> accList;
		set<string> s;
		cin >> n;
		char arr[30];

		//for(int i = 0; i < n; i++)
		while(n--)
		{
			scanf("\n%[^\n]s",arr);
			s.insert(arr);
			accList[arr]++;
		}
		
        for(auto el : s)
            cout << el << " " << accList[el] << endl;
	}
	return 0;
}