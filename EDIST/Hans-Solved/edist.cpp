#include <iostream>
#include <string>

using namespace std;

int memo[3000][3000];

int stringDistance(const string &a, const string &b)
{
    int n = a.size(), m = b.size();
    for(int i = 0; i <= m;i++)
        memo[i][0] = i;
    for(int i = 0; i <= n; i++)
        memo[0][i] = i;
    for(int i=0; i < m; i++)
        for(int j = 0; j < n; j++){
            if(a[i] == b[j])
                memo[i+1][j+1] = memo[i][j];
            else
                memo[i+1][j+1] = 1 + min(memo[i][j], min(memo[i][j+1], memo[i+1][j]));
        }
    return memo[m][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;

    while(t--)
    {
        string a,b; 
        cin >> a >> b;
        cout << stringDistance(a, b) << endl;
    }
}