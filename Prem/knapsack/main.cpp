#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v, cap;
    int S, N; cin >> S >> N;


    cap.push_back(-1);
    v.push_back(-1);

    int item_c, item_v;
    for (int i = 0; i < N; i++) {
        cin >> item_c   >> item_v;
        cap.push_back(item_c);
        v.push_back(item_v);
    }



    vector< vector<int> > size_allow(N + 1, vector<int>(S + 1, 0));

    for (int i = 1; i <= N; i++) { // creating a matrix to update the knapsack value
        for (int w = 1; w <= S; w++) { // is the size of the bag, checking every value
            if (cap[i] > w) {
                size_allow[i][w] = size_allow[i - 1][w];
            } else {
                size_allow[i][w] = max(size_allow[i - 1][w], v[i] + size_allow[i - 1][w - cap[i]]);
            }
        }
    }

    cout << size_allow[N][S];
}
