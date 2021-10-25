#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int to_id(int n, pair <int, int> coord) {
	return n * coord.first + coord.second;
}

bool is_valid(int n, pair <int, int> coord) {
	return coord.first > -1 && coord.first < n && coord.second > -1 && coord.second < n;
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
	fstream fin("p083_matrix.txt");
	string line;
	vector <vector <int>> matrix;
	while (getline(fin, line)) {
		matrix.push_back(separate(line));
	}
	int n = matrix.size();
	vector <int> dist(n * n, INF);
	bool vis[n * n] = {};
	priority_queue <pair<int, pair <int, int>>, vector<pair<int, pair <int, int>>>, greater<pair<int, pair <int, int>>>> q;
	q.push({matrix[0][0], {0, 0}});
	while (!q.empty()) {
		auto top = q.top();
		q.pop();
		int id = to_id(n, top.second);
		auto top_coord = top.second;
		if (vis[id]) {
			continue;
		}
		vis[id] = true;
		dist[id] = top.first;
		vector <pair <int, int>> to_vis({{top_coord.first - 1, top_coord.second}, {top_coord.first + 1, top_coord.second}, {top_coord.first, top_coord.second - 1}, {top_coord.first, top_coord.second + 1}});
		for (auto& p : to_vis) {
			if (is_valid(n, p) && !vis[to_id(n, p)]) {
				q.push({dist[id] + matrix[p.first][p.second], p});
			}
		}
	}
	cout << dist[n * n - 1] << endl;
	return 0;
}

