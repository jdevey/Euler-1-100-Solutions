#include <bits/stdc++.h>

using namespace std;

const int N = 10000;
bool sieve[N];
vector <int> p;

int sq(int n) {
	return n * n;
}

int cube(int n) {
	return n * n * n;
}

int four(int n) {
	return n * n * n * n;
}

int main() {
	for (int i = 2; i * i < N; ++i) {
		for (int j = sieve[i] ? N : i * i; j < N; j += i) {
			sieve[j] = true;
		}
	}
	for (int i = 2; i < N; ++i) {
		if (!sieve[i]) {
			p.push_back(i);
		}
	}
	int g = 50000000;
	bool* found = new bool[g]();
	for (int i = 0; four(p[i]) < g; ++i) {
		for (int j = 0; four(p[i]) + cube(p[j]) < g; ++j) {
			for (int k = 0;; ++k) {
				int sm = four(p[i]) + cube(p[j]) + sq(p[k]);
				if (sm < g) {
					found[sm] = true;
				}
				else {
					break;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < g; ++i) {
		cnt += found[i];
	}
	cout << cnt << endl;
	return 0;
}
