#include <iostream>
using namespace std;

long energy[1000002], ed[1002], t[1002]; // ed = "energy disintegrate" ;
int l = 0;

long ksack(long high)
{
    if(high <= 0) return 0;
    if(energy[high] != -1) return energy[high];

    energy[high]=0;

    for(int i=0; i<l;i++)
    {
        if(high-ed[i] >= 0)
        {
            energy[high] = max(energy[high], t[i] + ksack(high-ed[i]));
        }
    }
    return energy[high];

}

int main() {
//    std::cout << "Hello, World!" << std::endl;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int n;
long high;
cin>>n;
while(n--)
{
    cin >> high >> l;
    for(int i =0; i<=high;i++)
        energy[i]=-1;
    for(int i=0;i<l;i++)
        cin>>ed[i];
    for(int i=0;i<l;i++)
        cin>>t[i];

    cout << ksack(high) << endl;
}
    return 0;

}
