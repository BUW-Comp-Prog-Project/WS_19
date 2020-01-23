#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t, n, a[100005], count[100005], s[100005], i;
    long long int max, total;

    cin >> t;

    while(t--) 
    {
        cin >> n;
        max = -1000000000;
        total = 0;

        for(i = 0; i < n; i++) 
            cin >> a[i];

        s[0] = a[0];
        count[0] = 1;

        for(i = 1; i < n; i++) {
            if(s[i-1]+a[i] == a[i]) {
                s[i] = a[i];
                count[i] = count[i-1] + 1;
            }
            else if(s[i-1]+a[i] > a[i]) {
                s[i] = s[i-1] + a[i];
                count[i] = count[i-1];
            }
            else{
                s[i] = a[i];
                count[i] = 1;
            }
        }

        for(i = 0; i < n; i++) 
            if(s[i] > max) 
                max = s[i];

        for(i = 0; i < n; i++) 
            if(s[i] == max) 
                total = total + count[i];
            
        cout << max << " " << total << endl;
    }
}

