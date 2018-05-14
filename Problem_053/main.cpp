#include <bits/stdc++.h>

#define BIG 1000000

using namespace std;

int main() {

	int pascal[101][101] = {};
	for (int i = 0; i < 101; ++i) pascal[i][0] = 1;

	int cnt = 0;

	for (int i = 1; i < 101; ++i) {
		for (int j = 1; j <= i; ++j) {
			pascal[i][j] = min(BIG + 1, pascal[i - 1][j - 1] + pascal[i - 1][j]);
			if (pascal[i][j] > BIG) ++cnt;
		}
	}

	cout << cnt << endl;

    return 0;
}
