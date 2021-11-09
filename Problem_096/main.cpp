#include <bits/stdc++.h>

using namespace std;

bool dfs(vector <vector <int>>& board, int depth) {
	if (depth == 0) {
		return true;
	}
	bool open[10];
	vector <int> best_open;
	int mn = 9, best_row = 0, best_col = 0;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (board[i][j] == 0) {
				memset(open, 0, sizeof(open));
				for (int k = 0; k < 9; ++k) {
					open[board[i][k]] = true;
					open[board[k][j]] = true;
					open[board[i / 3 * 3 + k / 3][j / 3 * 3 + k % 3]] = true;
				}
				vector <int> cell_open;
				for (int k = 1; k <= 9; ++k) {
					if (!open[k]) {
						cell_open.push_back(k);
					}
				}
				if (cell_open.empty()) {
					return false;
				}
				if (cell_open.size() < mn) {
					mn = cell_open.size();
					best_open = cell_open;
					best_row = i;
					best_col = j;
				}
			}
		}
	}
	for (auto num : best_open) {
		board[best_row][best_col] = num;
		if (dfs(board, depth - 1)) {
			return true;
		}
		board[best_row][best_col] = 0;
	}
	return false;
}

int main() {
	freopen("p096_sudoku.txt", "r", stdin);
	int num_cases = 50, sm = 0;
	for (int t = 1; t <= num_cases; ++t) {
		string line;
		cin >> line >> line;
		vector <vector <int>> board(9, vector <int>());
		int zero_cnt = 0;
		for (int i = 0; i < 9; ++i) {
			cin >> line;
			for (auto c : line) {
				board[i].push_back(c - '0');
				zero_cnt += c == '0';
			}
		}
		dfs(board, zero_cnt);
		sm += board[0][0] * 100 + board[0][1] * 10 + board[0][2];
	}
	cout << sm << endl;
	return 0;
}

