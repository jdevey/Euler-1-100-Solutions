#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {

	map <string, vector <ull>> m;

	for (ull i = 1;; ++i) {
		ull cube = i * i * i;
		string s = to_string(cube);
		sort(s.begin(), s.end());
		m[s].push_back(cube);
		if (m[s].size() == 5) {
			cout << m[s][0] << endl;
			break;
		}
	}

	return 0;
}
