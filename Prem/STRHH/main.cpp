#include <iostream>
#include <cstring>

//strlen() is a function included in cstring library

using namespace std;

void halfofhalf(char c[], int i){
    int index = 0;
    while(index < i){
        cout << c[index];
        index+=2;
    }
    cout << endl;
}

int main() {
    int n;
    char c[300];
    cin>>n;
//    string s;
    while(n--)
    {
        cin >> c;
        halfofhalf(c, strlen(c)/2);

    }

    return 0;
}
