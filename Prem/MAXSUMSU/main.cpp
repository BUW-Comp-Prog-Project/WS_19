#include <iostream>
#include <algorithm>
int a[100002];

int globalmax(int n)
{
    int l_max = a[0];
    int g_max = a[0];
    for(int i = 1; i < n; i++)
    {
        l_max = std::max(a[i], (l_max + a[i]));
        g_max = std::max(l_max, g_max);
    }
    return g_max;
}

using namespace std;
int main() {
    int t, n, global_max;

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i= 0; i<n;i++)
        {
           cin >>  a[i];
        }
        global_max = globalmax(n);
        cout << global_max << endl;
    }
    return 0;
}
