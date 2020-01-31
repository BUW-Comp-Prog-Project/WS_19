#include <iostream>

using namespace std;

int main()
{
	int n,i,j,k, tmp, color[100][100], smoke[100][100], a[100];
	
    while(cin >> n)
	{
		for (i = 0; i < n; i++)
		{
			cin >> color[i][i];
            smoke[i][i] = 0;
            a[i] = color[i][i];
		}
		for (i = 1; i < n; i++)
			for (j = 0; j < n-i; j++)
			{
				smoke[j][i+j]=1000000000;
				for (k = 0; k < i; k++)
				{
					color[j][i+j] = (color[j+1][i+j]+a[j]) % 100;
					smoke[j][i+j] = min(smoke[j][i+j],
						smoke[j][j+k] + smoke[j+k+1][j+i] + color[j][j+k] * color[j+k+1][j+i]);
				}
			}
		cout << smoke[0][n-1] << endl;
	}
}