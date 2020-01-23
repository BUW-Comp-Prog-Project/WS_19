#include <iostream>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while (t --) {
        cin >> n;
        int ans = 0, sum = 0;
        for (int i = 0; i < n; ++ i) {
            int a;
            cin >> a;
            sum += a;
            ans = max(ans, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}