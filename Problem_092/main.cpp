#include <bits/stdc++.h>

using namespace std;

int get_sum(int n) {
	int sm = 0;
	while (n) {
		sm += n % 10 * (n % 10);
		n /= 10;
	}
	return sm;
}

int main() {
	const int mx = 10000000;
	int* ans = new int[mx];
	for (int i = 1; i < mx; ++i) {
		int curr = i;
		while (curr != 1 && curr != 89) {
			if (ans[curr] != 0) {
				curr = ans[curr];
				break;
			}
			curr = get_sum(curr);
		}
		ans[i] = curr;
	}
	int sm = 0;
	for (int i = 1; i < mx; ++i) {
		sm += ans[i] == 89;
	}
	cout << sm << endl;
	return 0;
}
