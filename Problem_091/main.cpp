#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int cross(pair <int, int> a, pair <int, int> b) {
	return a.first * b.second - a.second * b.first;
}

pair <int, int> make_std(pair <int, int>& v) {
	int g = gcd(v.first, v.second);
	return {v.first / g, v.second / g};
}

bool dependent(pair <int, int> a, pair <int, int> b) {
	return make_std(a) == make_std(b);
}

bool is_right(pair <int, int> a, pair <int, int> b) {
	return dependent(make_pair(-a.second, a.first), b);
}

bool are_any_right(pair <int, int> a, pair <int, int> b) {
	if (a == b || a == make_pair(0, 0) || b == make_pair(0, 0)) {
		return false;
	}
	if (cross(a, b) < 0) {
		swap(a, b);
	}
	pair <pair <int, int>, pair <int, int>> p1 = {a, b}, p2 = {{b.first - a.first, b.second - a.second}, {-a.first, -a.second}}, p3 = {{-b.first, -b.second}, {a.first - b.first, a.second - b.second}};
	return is_right(p1.first, p1.second) || is_right(p2.first, p2.second) || is_right(p3.first, p3.second);
}

int main() {
	int n = 51, sm = 0;
	for (int i = 0; i < n * n; ++i) {
		for (int j = 0; j < i; ++j) {
			sm += are_any_right({i / n, i % n}, {j / n, j % n});
		}
	}
	cout << sm << endl;
	return 0;
}
