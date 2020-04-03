#include <iostream>
using namespace std;

int main() {
//    std::cout << "Hello, World!" << std::endl;
    int t, l,c;
    cin>>t;
    while(t--)
    {
        cin >> l >> c;

//    int counter = 1;
        for(int i= 0; i<(l*3)+1;i++){
            for(int j=0; j<(c*3)+1;j++){

                if(i%3==0 || j%3 ==0)
                {
                    cout<<"*";
//              counter+=1;
                } else
                {
                    cout<<".";
//                counter+=1;
                }
            }
            cout<<endl;
//        cout<<counter;
        }
        cout<<endl;
    }

    return 0;

}
