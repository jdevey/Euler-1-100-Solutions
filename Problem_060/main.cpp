#include <bits/stdc++.h>

#define BIG 100000000

using namespace std;

bool* a;
vector <int> primeList;

void eratosthenes() {
	memset(a, 0, sizeof(a));
	for (int i = 2; i < BIG; ++i) {
		for (int j = a[i] ? BIG : i << 1; j < BIG; j += i) {
			a[j] = true;
		}
	}
}

bool isPrime(int n) {
	return !a[n];
}

int numDig(int n) {
	return to_string(n).size();
}

pair <int, int> makeConcat(int a, int b) {
	return {a * pow(10, numDig(b)) + b, b * pow(10, numDig(a)) + a};
}

bool isPrimePair(pair <int, int> pll) {
	return isPrime(pll.first) & isPrime(pll.second);
}

bool isValidAddition(vector <int>& vll, int num) {
	for (auto x : vll) if (!isPrimePair(makeConcat(x, num))) return false;
	return true;
}

int vecSum(vector <int>& vi) {
	int sm = 0;
	for (auto x : vi) sm += x;
	return sm;
}

int main() {

	a = new bool[BIG];
	eratosthenes();

	vector <vector <vector <int>>> vvvll(5, vector <vector <int>>());

	int minSum = 1000000;

	for (int i = 2;; ++i) {
		if (a[i]) continue;
		for (int j = 0; j < 5; ++j) {
			if (j == 0) {
				if (!a[i]) vvvll[0].push_back(vector <int>(1, i));
			}
			else {
				for (auto x : vvvll[j - 1]) {
					if (isValidAddition(x, i)) {
						vector <int> vll = x;
						vll.push_back(i);
						vvvll[j].push_back(vll);
						if (j == 4) {
							minSum = min(minSum, vecSum(vvvll[4].back()));
							cout << minSum << endl;
							if (vvvll[4].size()) return 0;
						}
					}
				}
			}
		}
	}

	return 0;
}
