#include <bits/stdc++.h>

using namespace std;

int main() {

	set <pair <int, int>> s;

	for (int i = 1; i <= 12000; ++i) {
		for (int j = i / 3 + 1; j < (i + 1) / 2; ++j) {
			s.insert({i / __gcd(i, j), j / __gcd(i, j)});
		}
	}

	cout << s.size() << endl;

	return 0;
}
