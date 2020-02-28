//https://www.spoj.com/problems/PERMUT2/
#include<iostream>
using namespace std;

int main(){
    int N,mark;
    int A[200001] ;
    while(cin>>N)

    {
        if(N==0)
            return 0;
        for(int i=1;i<=N;i++) cin>>A[i];
        mark=1;

        for(int i=1;i<=N;i++){
            if(A[A[i]]!=i){ mark=0; break;}
        }
        if(mark==1)
        {cout<<"ambiguous"<<endl;}

        else
        {cout<<"not ambiguous"<<endl;}
    }
}