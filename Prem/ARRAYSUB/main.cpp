// https://www.spoj.com/problems/ARRAYSUB/
#include <iostream>
#include <deque>
#include <vector>


using namespace std;
int a[100002];

int main() {
    int n, k;
    vector<int> output;
        cin >> n ;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];

        }


    cin >> k;
    deque<int> dq(k);
    for(int i = 0; i < k ; i++)
    {
        while(!dq.empty()&&a[i]>a[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(int i = k; i<n; i++)
    {
        output.push_back(a[dq.front()]);

        while(!dq.empty()&&a[i]>a[dq.back()])
        {
            dq.pop_back();
        }

        while(!dq.empty() && dq.front() <=(i-k))
        {
            dq.pop_front();
        }
        dq.push_back(i);
    }

    if(!dq.empty()) output.push_back(a[dq.front()]);

    for(int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }



    return 0;
}
