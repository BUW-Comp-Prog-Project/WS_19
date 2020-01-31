#include<iostream>
#include<string>

using namespace std;

//TLE OR SIGSEV DEPENDING ON METHOD...

int LCS(string &a, string &b) 
{ 
    int n = a.length(), m = b.length(), max = 0, memo[2][n], currentRow = 0; 

    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0 || j == 0)
                memo[currentRow][j] = 0;  
            else if (a[i - 1] == b[j - 1]) { 
                memo[currentRow][j] = memo[1 - currentRow][j - 1] + 1; 
                if (memo[currentRow][j] > max) 
                    max = memo[currentRow][j];
            } 
            else 
                memo[currentRow][j] = 0;
        } 
        currentRow = 1 - currentRow; 
    } 
    return max;
} 

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    cout << LCS(a, b);
}

