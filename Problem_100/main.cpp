#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string to_string(__int128 n) {
	string s;
	while (n > 0) {
		s = to_string((int8_t)(n % 10)) + s;
		n /= 10;
	}
	return s;
}

int main() {
	__int128 leading = 1e12, trailing = leading / sqrt(2), t, l;
	for (;; leading += leading & 1 ? 3 : 1) {
		while ((t = trailing * (trailing - 1) * 2) < (l = leading * (leading - 1))) {
			++trailing;
		}
		if (t == l) {
			cout << to_string(trailing) << endl;
			return 0;
		}
	}
}

