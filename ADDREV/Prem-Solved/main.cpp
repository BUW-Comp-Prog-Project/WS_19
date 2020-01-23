#include <iostream>
using namespace std;
unsigned long int rev(int a);
int main(){
    int cases;
    std::cin >> cases;


    //int i = 0;
    while (cases--)
    {

        unsigned long int a,b;
        std::cin >> a;
        std::cin >> b;
        std::cout << rev(rev(a)+rev(b)) << '\n';
        //i++;
    }

    return 0;
}


unsigned long int rev(int a){
    unsigned long int r = a%10;
    unsigned long int q = a/10;
    unsigned long int ans=r;
    while(q>0){
        r = q %10;
        q= q/10;
        ans = ans*10 + r;
    }
    return ans;
}
