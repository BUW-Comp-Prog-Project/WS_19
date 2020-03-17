#include <iostream>

using namespace std;

int main()
{
    int num;
    bool c = True;

    while(c)
    {
        cin >> num;
        if (num == 42)
            break;
        cout << num << "\n";
    }

    return 0;
}