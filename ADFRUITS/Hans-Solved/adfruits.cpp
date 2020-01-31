#include <iostream>
#include <string>
using namespace std;

int memo[101][101];
bool checkA[101], checkB[101];
int lenA, lenB;


void prepareMatrices(string &a, string &b)
{
    for(int i = 0; i <= lenA; i++)
        for(int j = 0; j <= lenB; j++)
        {
            if(i == 0 || j == 0)
                memo[i][j] = 0;
            else if(a[i-1] == b[j-1])
                memo[i][j] = memo[i-1][j-1] + 1;
            else
                memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
        }

    fill(checkA, checkA + lenA, false);
    fill(checkB, checkB + lenB, false);

    int i = lenA;
    int j = lenB;
    while(i > 0 && j > 0)
    {
        if(a[i-1] == b[j-1])
        {
            checkA[i-1] = true;
            checkB[j-1] = true;
            i--;
            j--;
        }
        else
            (memo[i][j-1] >= memo[i-1][j]) ? (j--) : (i--);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string a, b;
    while(cin >> a >> b)
    {
        lenA = a.size(), lenB = b.size();
        prepareMatrices(a, b);
        int k = 0, l = 0;

        while(k < lenA && l < lenB)
        {
            while(k < lenA && !checkA[k])
            {
                cout << a[k];
                k++;
            }
            while(l < lenB && !checkB[l])
            {
                cout << b[l];
                l++;
            }

            while(k < lenA && l < lenB && checkA[k] && checkB[l])
            {
                cout << a[k];
                k++;
                l++;
            }
        }
            
        while(k < lenA)
        {
            cout << a[k];
            k++;
        }

        while(l < lenB)
        {
            cout << b[l];
            l++;
        }

        cout << endl;
    }
    return 0;
}