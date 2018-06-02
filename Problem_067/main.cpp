#include <bits/stdc++.h>

using namespace std;

int main() {

	ifstream fin("triangle.txt");

	int dp[100][100] = {}, mx = 0;
	fin >> dp[0][0];

	for (int i = 1; i < 100; ++i) {
		int temp;
		for (int j = 0; j <= i; ++j) {
			fin >> temp;
			dp[i][j] = temp + max(j > 0 ? dp[i - 1][j - 1] : 0, j < i ? dp[i - 1][j] : 0);
		}
	}

	for_each(begin(dp[99]), end(dp[99]), [&mx](int elem){mx = max(mx, elem);});
	cout << mx << endl;

	return 0;
}
