// https://www.spoj.com/BSCPROG/problems/SMPDIV/

#include <iostream>


using namespace std;
long int a[10000];
int array_define(int n, int x)
{
    int multiple = x;
    int i = 1;
    a[i]=x;
//    cout << a[i] << "  ";
    while(n>multiple)
    {
        i = i+1;
        multiple = x*i;
        a[i]=multiple;
//        cout << a[i] << "  ";
    }
    return i;
}

int main() {
    int t, n, x, y;
    cin >>t ;
//    cout<< "loop";
    while(t--)
    {
        cin >> n >> x >> y;
        int i = array_define(n,x);
//        cout<< "loop"; we have to consider from 1 to i-1
//        i--;
        for(int j=1; j<i; j++)
        {
            if((a[j]%y) !=0)
            {
                cout << a[j] << " ";
            }
        }

    }
    return 0;
}
