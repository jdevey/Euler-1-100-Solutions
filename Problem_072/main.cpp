#include <bits/stdc++.h>

#define MAX 1000000

using namespace std;

long long totient(vector <int>* pFac, long long num) {
	for (auto x : pFac[num]) num = num * (x - 1) / x;
	return num;
}

int main() {
	vector <int>* pFac = new vector <int>[MAX + 1]();
	for (int i = 2; i <= MAX; ++i) {
		for (int j = pFac[i].empty() ? i : MAX + 1; j <= MAX; j += i) pFac[j].push_back(i);
	}
	long long sm = 0;
	for (int i = 2; i <= MAX; ++i) sm += totient(pFac, i);
	cout << sm << endl;
	return 0;
}
