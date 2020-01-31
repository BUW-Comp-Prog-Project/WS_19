#include<iostream>
using namespace std;

long mem[1000001], v[1001], w[1001], counter = 0;

long knapsack(long val)
{
	if(val <= 0)
	    return 0;
	
	if(mem[val] != -1)
	    return mem[val];
	
	mem[val]=0;

	for(long i = 0; i < counter; i++)
	{
		if(val - v[i] >= 0)
		    mem[val] = max(mem[val], w[i] + knapsack(val - v[i]));
	}
	return mem[val];
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while(n--)
	{
		long val, i, j, k;
        cin >> val >> counter;
		
		for(i = 0; i <= val; i++)
		    mem[i]=-1;
		for(i = 0; i < counter; i++)
		    cin >> v[i];
		for(i = 0; i < counter; i++)
	        cin >> w[i];
		
		cout << knapsack(val) << endl;
	}
}