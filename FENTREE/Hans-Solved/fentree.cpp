#include <iostream>

using namespace std;

const int maxLen = 1000025;

int n, q, x, y;
char type;
int freqs[maxLen];
long long fenTree[maxLen];

void addValue(int pos, int value) {
	for (; pos < maxLen; pos += (pos & -pos))
		fenTree[pos] += value;
}
long long getValue(int pos) {
	long long s = 0;
	for (; pos > 0; pos -= (pos & -pos))
		s += fenTree[pos];
	return s;
}
long long getValueRange(int l, int r) {
	return getValue(r) - getValue(l - 1);
}

int main(int argc, const char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> freqs[i];
		addValue(i, freqs[i]);
	}
	cin >> q;
	while (q--) {
		cin >> type >> x >> y;
		if (type == 'u') {
			addValue(x, y);
			freqs[x] += y;
		}
		else {
			cout << getValueRange(x, y) << "\n";
		}
	}
	return 0;
}