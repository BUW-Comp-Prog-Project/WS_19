#include<iostream>
#include<map>

using namespace std;

map<long, long>mem;

long genChange(long n)
{
	if(mem[n]!=0)
		return mem[n];
	
	if(n/2 + n/3 + n/4 > n)
		return mem[n] = genChange(n/2) + genChange(n/3) + genChange(n/4); 
	
	if(n/2 + n/3 + n/4 <= n)
		return n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long n;	
	while(cin >> n)
	{
        cout << genChange(n) << endl;
	}
}