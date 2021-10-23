#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pentagonal(ll n) {
	return n * (3 * n - 1) / 2;
}

int main() {

	vector <ll> exp;
	for (ll i = 1; pentagonal(i) <= 100; ++i) {
		exp.push_back(pentagonal(i) * (~i & 1 ? -1 : 1));
		exp.push_back(pentagonal(-i) * (~i & 1 ? -1 : 1));
	}

	ll dp[101]{};
	dp[0] = 1;
	for (ll i = 1; i <= 100; ++i) {
		for (auto j : exp) {
			if (abs(j) > i) break;
			dp[i] += dp[i - abs(j)] * (j < 0 ? -1 : 1);
		}
		cout << i << " " << dp[i] << endl;
	}

	cout << dp[100] - 1 << endl;

	return 0;
}
