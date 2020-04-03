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
    for(int i= 0; i<l;i++){
        for(int j=0; j<c;j++){
            int counter = i+j;
          if(counter%2==0)
          {
              cout<<"*";
//              counter+=1;
          } else if (counter%2!=0)
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
//if(t>0)
//{
//    cout<<endl;
//}
    return 0;

}
