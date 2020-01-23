#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ull;
typedef long long int ll;
typedef vector<long long int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
map<int,int> visit;
ll maxi=1,mini=1;
ll co=0;
int root(int x)
{
    while(x!=visit[x])
    {
        visit[x]=visit[visit[x]];
        x=visit[x];
    }
    return x;
}
void unin(int a,int b)
{
    visit[(b)]=(a);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll n,sum=0,count=0,m,flag=0,ans=0;
    cin>>n>>m;
    co=n;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(!visit[x])
            visit[x]=x;
        if(!visit[y])
            visit[y]=y;
        ll a=root(x);
        ll b=root(y);
        if(a!=b)
        {
            co--;
            unin(a,b);
        }
    }

    cout<<co;
    return 0;
}