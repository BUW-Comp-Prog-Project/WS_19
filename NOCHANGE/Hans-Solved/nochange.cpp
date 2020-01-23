#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n,t;
    cin >> n >> t;
    int a[t],i,j;

    for(i = 0; i < t; i++)
    {
        cin >> a[i];
        if(i > 0)
            a[i] += a[i-1];
    }
    
    bool ans[n+1];

    ans[0]=true;
    
    for(i = 1; i <= n; i++)
        ans[i]=false;

    for(i = 0; i < t; i++)
        for(j = a[i]; j<=n; j++)
            ans[j] |= ans[j-a[i]];  
    
    (ans[n]) ? cout << "YES" : cout << "NO";
    cout << endl;
    return 0;
}