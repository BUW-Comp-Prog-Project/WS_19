

#include<stdio.h>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include<limits.h>
using namespace std;

int gcd(int m,int n)
{
    if(m==0)return n;
    return gcd(n%m,m);
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        set<pair<int,int> > mp;
        int i,x[n],y[n],j;
        for(i=0;i<n;i++)
            scanf("%d %d",&x[i],&y[i]);
        int mx,my,m;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                my=(y[j]-y[i]);
                mx=(x[j]-x[i ]);
                m=gcd(mx,my);
                if(m!=0){
                    my/=m;mx/=m;
                    if(mx<0)
                    {mx*=-1;my*=-1;}
                }
                mp.insert(make_pair(mx,my));
            }
        }
        printf("%d\n",mp.size());
        scanf("%d",&n);
    }

    return 0;}

