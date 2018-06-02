#include <bits/stdc++.h>

#define MAX 10000000

using namespace std;

long long totient(vector <int>* pFac, long long num) {
	for (auto x : pFac[num]) num = num * (x - 1) / x;
	return num;
}

bool isPerm(int n1, int n2) {
	int cs1[10] = {}, cs2[10] = {};
	while (n1) {
		++cs1[n1 % 10];
		n1 /= 10;
	}
	while (n2) {
		++cs2[n2 % 10];
		n2 /= 10;
	}
	return equal(cs1, cs1 + 10, cs2);
}

int main() {

	vector <int>* pFac = new vector <int>[MAX]();
	for (int i = 2; i < MAX; ++i) {
		for (int j = pFac[i].empty() ? i : MAX; j < MAX; j += i) pFac[j].push_back(i);
	}

	long double minRatio = 1e9;
	int minVal;
	for (int i = 2; i < MAX; ++i) {
		int t = totient(pFac, i);
		if (isPerm(i, t) && (long double)i / t < minRatio) {
			minRatio = (long double)i / t;
			minVal = i;
		}
	}

	cout << minVal << endl;

	return 0;
}
