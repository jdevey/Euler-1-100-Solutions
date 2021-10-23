#include <bits/stdc++.h>

using namespace std;

const int SIEVE_MAX = 10000000;
bool* eratosthenes = new bool[SIEVE_MAX];

void fill_eratosthenes() {
	memset(eratosthenes, false, sizeof(eratosthenes));
	for (int i = 2; i * i < SIEVE_MAX; ++i) {
		for (int j = eratosthenes[i] ? SIEVE_MAX : i * i; j < SIEVE_MAX; j += i) {
			eratosthenes[j] = true;
		}
	}
}

vector <int> get_primes() {
	static vector <int> primes;
	if (primes.empty()) {
		fill_eratosthenes();
		for (int i = 2; i < SIEVE_MAX; ++i) {
			if (!eratosthenes[i]) {
				primes.push_back(i);
			}
		}
	}
	return primes;
}

int nth_prime(int n) {
	static vector <int> primes = get_primes();
	return primes[n];
}

int main() {
	// dp[i][j] = the number of ways to write the integer i as the sum of primes such that the minimum prime in the sum is j
	int upper = 100, dp[upper][upper] = {};
	for (int i = 2; i < upper; ++i) {
		int sum = 0;
		for (int j = 0, min_prime = nth_prime(j); min_prime <= i; ++j, min_prime = nth_prime(j)) {
			if (i == min_prime) {
				dp[i][j] = 1;
			}
			else {
				for (int k = j, back_prime = nth_prime(k); min_prime + back_prime <= i; ++k, back_prime = nth_prime(k)) {
					dp[i][j] += dp[i - min_prime][k];
				}
			}
			sum += dp[i][j];
		}
		if (sum > 5000) {
			cout << i << ' ' << sum << endl;
			return 0;
		}
	}
	return 0;
}

