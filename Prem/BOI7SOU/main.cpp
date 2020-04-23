//https://www.spoj.com/problems/BOI7SOU/

#include <iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
int a[1000010];
vector<int> vec;
multiset<int> ms;


int main() {
//    std::cout << "Hello, World!" << std::endl;
int n,m,c, temp;
cin>>n>>m>>c;
for(int i =1; i<=n; i++){
    cin>>a[i];
}

for(int i=1;i<=n;i++){
    ms.insert(a[i]);
    if(i>m)
    {
        ms.erase(ms.find(a[i-m]));
    }
    if(i>=m)
    {
        if(*(--ms.end())-(*ms.begin()) <=c)
          vec.push_back(i-m+1);

    }
    bool is_empty = vec.empty();
    if(is_empty)
    {
        cout<<"NONE"<<endl;
    } else{
        for(int i:vec) cout << i << endl;
    }
}
    return 0;

}
