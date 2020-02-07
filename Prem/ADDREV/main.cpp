#include <iostream>
using namespace std;

unsigned long int reverse(int a){
    unsigned long int rem = a%10;
    unsigned long int quo = a/10;
    unsigned long int ans=rem;
    while(quo>0){
        rem = quo %10;
        quo= quo/10;
        ans = ans*10 + rem;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;

    while (n--)
    {

        unsigned long int a,b, sum_rev;
        cin >> a;
        cin >> b;
        sum_rev = reverse(a) + reverse(b);
        cout << reverse(sum_rev) << '\n';
//        n--;
    }

    return 0;
}


