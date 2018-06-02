#include <bits/stdc++.h>

using namespace std;

int sumFac(int* fac, int n) {
	int sm = 0;
	while (n) {
		sm += fac[n % 10];
		n /= 10;
	}
	return sm;
}

int main() {

	int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}, cnt = 0;

	for (int i = 1; i < 1000000; ++i) {
		set <int> s;
		int val = i;
		while (s.find(val) == s.end()) {
			s.insert(val);
			val = sumFac(fac, val);
		}
		if (s.size() == 60) ++cnt;
	}

	cout << cnt << endl;

	return 0;
}
