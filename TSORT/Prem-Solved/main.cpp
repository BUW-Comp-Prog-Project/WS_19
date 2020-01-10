//https://www.spoj.com/problems/TSORT/
#include <iostream>
#include <set>
#define  ull unsigned long long int

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    multiset<int> s1;

int n;
int i;
cin >> n;
while(n--)
{
    cin >> i ;
    s1.insert(i);
}
n = s1.size();
multiset<int>::iterator it;
for(it = s1.begin();it!=s1.end();it++)
{
    cout << *it << '\n';
}


return 0;

}