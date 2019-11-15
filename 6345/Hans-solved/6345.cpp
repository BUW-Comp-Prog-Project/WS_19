#include <iostream>
using namespace std;

int main()
{
    int t,n,m,k,sum, a[50], i, j, sPos, max;
    char c;
    cin >> t;
    
    while(t--)
    {
        sum = 0;
 
        cin >> n >> m >> k;

        for(i = 0; i < n; i++)
        {
            a[i] = 0;

            for(j = 0; j < m; j++)
            {
                cin >> c;
                if(c == '.')
                    a[i]++; 
            }
        }

        for(i = 0; i < k; i++)
        {
            max = 0;
            for(j = 0; j < n; j++)
                if(a[j] > max)
                {
                    sPos = j;
                    max = a[j];
                }

            (max == 0) ? a[0] = m : a[sPos] = m-max;
        }

        for(i = 0; i < n; i++)
            sum += m - a[i]; 

        cout << sum << endl;
    }
    return 0;
}