#include <bits/stdc++.h>

using namespace std;

int euclidean(int n, int m) {
	return m == 0 ? n : euclidean(m, n % m);
}

int main() {

	int squares[101];
	for (int i = 1; i <= 100; ++i) squares[i] = i * i;
	int sqpt = 1;

	int oddCount = 0;
	vector <vector <pair <int, int>>> sequences;
	for (int i = 1; i <= 10000; ++i) {
		if (i == squares[sqpt]) {
			++sqpt;
			continue;
		}
		int a = 1, b = sqrt(i), d = 1;
		set <tuple <int, int, int>> sp; //Let first be a, second be b, and third be d
		vector <pair <int, int>> vp;
		sp.insert({1, sqrt(i), 1});
		vp.push_back({sqrt(i), i});
		while (true) {
			int newA = d * a;
			int newB = d * b;
			int newD = a * a * i - b * b;
			int gcd = euclidean(newD, d);
			newD /= gcd;
			newA /= gcd;
			newB /= gcd;
			int seq = (newA * sqrt(i) + newB) / newD;
			vp.push_back({seq, i});
			newB -= newD * seq;
			newB = abs(newB);
			a = newA;
			b = newB;
			d = newD;
			if (sp.find({a, b, d}) != sp.end()) {
				if (sp.size() & 1) ++oddCount;
				sequences.push_back(vp);
				break;
			}
			sp.insert({a, b, d});
		}
	}

	cout << oddCount;

	return 0;
}

