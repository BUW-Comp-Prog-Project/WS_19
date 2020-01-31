#include <iostream>
#include <string>

//NOT WORKING BUT HERE WE GO

using namespace std;

//int memo[100000][100000];

int strDist(string &a, string &b)
{
    int lenA = a.length(), lenB = b.length(), i, j, cost;
    int mem[lenA+1][lenB+1];

    for (i = 0; i <= lenA;i++)
        mem[i][0] = i;
    for(j = 0; j <= lenB; j++)
        mem[0][j] = j;
    for (i = 1; i <= lenA; i++)
    {
        for(j = 1; j <= lenB; j++)
        {
            if(a[i-1] == b[j-1] )
                cost = 0;
            else
                cost = 1;
            mem[i][j] = std::min(
            mem[i-1][j] + 1,                // delete
            min(mem[i][j-1] + 1,            // insert
            mem[i-1][j-1] + cost)           // substitution
            );
            
            if((i > 1) && 
            (j > 1) && 
            (a[i-1] == b[j-2]) && 
            (a[i-2] == b[j-1])) 
            {
                mem[i][j] = min(
                mem[i][j],
                mem[i-2][j-2] + cost   // transposition
                );
            }
        }
    }
    return mem[lenA][lenB];
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    //int n, m;
    string a,b; 
    while(cin >> a >> b)
    {
        cout << strDist(a, b) << endl;      
    }
}