//https://www.spoj.com/problems/BTCK/
#include <iostream>
#include <vector>
#include <fstream>

using  namespace std;

int k, dim = 10, offset = 0;
vector<int> permutation;

bool operator < (vector<int> const& a, vector<int> const& b){
    for(int i = 0; i < dim; ++i){
        if(a.at(i) < b.at(i)) {
            return true;
        }else if(a.at(i) > b.at(i)) {
            return false;
        }
    }
    return true;
}

void increase_palindrome(vector<int>& a){
    int t,p;

    for(int i = a.size() - 1; i > 0; --i){
        if(a.at(i) > a.at(i - 1)){
            t = i-1;
            break;
        }
    }

    for(int i = a.size() - 1; i > t; --i){
        if(a.at(t) < a.at(i)) {
            p = i;
            break;
        }
    }

    swap(a.at(t), a.at(p));

    for(int i = 0; i < (a.size() - 1 - t)/2; ++i){
        swap(a.at(t + 1 + i), a.at(a.size() - 1 - i));
    }
}

void find_permutation(vector<int> const& input, vector<int>& elements){
    bool finished = false;

    while(!finished) {
        unsigned long long tmp = 0;
        for(int i = 0; i < dim; ++i) {
            tmp += input.at(i) * elements.at(i);
            if(tmp > k) {
                break;
            }
        }
        if(tmp <= k) {
            permutation = elements;
            return;
        }
        increase_palindrome(elements);
        finished = true;
        for(int i = 0; i < elements.size() - 1; ++i){
            if(elements.at(i) < elements.at(i + 1)){
                finished = false;
            }
        }
    }
}

int main() {
    int cases, tmp;

    ifstream cin ("C:\\Users\\Mortiferum\\CLionProjects\\WS_19\\28587\\Anton-Solved\\in.txt");

    cin >> cases;

    for(int i = 0; i < cases; ++i){
        permutation.clear();
        vector<int> input, elements;
        for(int j = 0; j < dim; ++j){
            cin >> tmp;
            input.push_back(tmp);
            elements.push_back(j + offset);
        }

        cin >> k;

        find_permutation(input, elements);

        if(permutation.size() > 0){
            for(int p = 0; p < dim; ++p){
                cout << permutation.at(p);
                if(p != dim - 1)
                    cout << " ";
            }
        } else {
            cout << "-1";
        }
        cout << endl;
    }

    return 0;
}