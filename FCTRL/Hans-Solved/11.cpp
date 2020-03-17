#include<iostream>
using namespace std;

int main(){
    int a,zeros,num,i,n,j;
    cin >> n;
    while(n--){   
        cin >> num;
        a=5;
        zeros=0 ;
        while(num/a!=0)
        {					
            zeros+=num/a;
            a=a*5;		//increasing a to powers of 5
        }
        cout << zeros << endl;
    }
    return 0;
}