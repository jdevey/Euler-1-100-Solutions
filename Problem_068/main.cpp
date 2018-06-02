#include <bits/stdc++.h>

using namespace std;

bool is5Gon(int* perm) {
	int sm = perm[0] + perm[1] + perm[5];
	for (int i = 0; i < 5; ++i) if (perm[i] == 10 || perm[i] + perm[(i + 1) % 5] + perm[i + 5] != sm) return false;
	return true;
}

string formString(int* perm) {
	string ans;
	int mn = 10, ind;
	for (int i = 5; i < 10; ++i) {
		if (perm[i] < mn) {
			mn = perm[i];
			ind = i;
		}
	}
	ind -= 5;
	for (int i = ind, cnt = 0; cnt < 5; ++cnt, i = (i + 1) % 5) {
		ans += to_string(perm[i + 5] * 100 + perm[i] * 10 + perm[(i + 1) % 5]);
	}
	return ans;
}

int main() {

	int perm[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	vector <string> ans;

	do {
		if (is5Gon(perm)) {
			ans.push_back(formString(perm));
		}
	} while (next_permutation(perm, perm + 10));

	sort(ans.begin(), ans.end());

	cout << ans.back() << endl;

	return 0;
}
