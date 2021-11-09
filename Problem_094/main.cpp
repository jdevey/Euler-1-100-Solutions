#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_square(ll n) {
	ll root = sqrt(n);
	return root * root == n;
}

bool is_good(ll hypot, ll base) {
	return is_square(hypot * hypot - base * base / 4);
}

int main() {
	ll mx = 333333334, sm = 0;
	// Base length must be even since sqrt(even * even - (odd / 2) * (odd / 2)) * odd cannot be integral
	for (ll n = 3; n <= mx; n += 2) {
		if (is_good(n, n - 1)) {
			sm += n * 2 + n - 1;
		}
		if (is_good(n, n + 1)) {
			sm += n * 2 + n + 1;
		}
	}
	cout << sm << endl;
	return 0;
}
