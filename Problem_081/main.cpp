#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

template <typename T>
void print_vec (vector <T> vec) {
	for (auto elem : vec) {
		cout << elem << " ";
	}
	cout << endl;
}

vector <int> separate(string line) {
	vector <int> ans;
	string value;
	for (auto c : line) {
		if (c == ',') {
			ans.push_back(stoi(value));
			value.clear();
		}
		else {
			value += c;
		}
	}
	ans.push_back(stoi(value));
	return ans;
}

int main() {
	fstream fin("p081_matrix.txt");
	string line;
	int n = 80;
	vector <vector <int>> matrix, dp(n, vector<int>(n, INF));
	while (getline(fin, line)) {
		matrix.push_back(separate(line));
	}
	dp[0][0] = matrix[0][0];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j] = min({dp[i][j], i == 0 ? INF : matrix[i][j] + dp[i - 1][j], j == 0 ? INF : matrix[i][j] + dp[i][j - 1]});
		}
	}
	cout << dp[n - 1][n - 1] << endl;
	return 0;
}

