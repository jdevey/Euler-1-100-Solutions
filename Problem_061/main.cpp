#include <bits/stdc++.h>

using namespace std;

typedef int (*polygon)(int);

struct Node {
	int val, color;
	vector <int> edges;
	Node(int _val, int _color) {
		val = _val;
		color = _color;
	}
};

int triangle(int n) {
	return n * (n + 1) / 2;
}

int square(int n) {
	return n * n;
}

int pentagonal(int n) {
	return n * (3 * n - 1) / 2;
}

int hexagonal(int n) {
	return n * (2 * n - 1);
}

int heptagonal(int n) {
	return n * (5 * n - 3) / 2;
}

int octagonal(int n) {
	return n * (3 * n - 2);
}

void dfs(vector <Node*> adj, bool* tempVis, vector <int> colors, int& orig, int ind, int depth, int sum) {
	if (ind == orig && depth == 6 && all_of(colors.begin(), colors.end(), [&](int i){return i == 1;})) {
		cout << sum << endl;
		exit(0);
	}
	if (tempVis[ind] || depth == 6 || colors[adj[ind]->color] > 0) {
		return;
	}
	tempVis[ind] = true;
	++colors[adj[ind]->color];
	for (auto x : adj[ind]->edges) {
		dfs(adj, tempVis, colors, orig, x, depth + 1, sum + adj[ind]->val);
	}
}

int main() {

	polygon func[] = {
		triangle,
		square,
		pentagonal,
		hexagonal,
		heptagonal,
		octagonal
	};

	vector <vector <int>> nums(6, vector <int>());

	for (int i = 0; i < 6; ++i) {
		for (int j = 1;; ++j) {
			if (func[i](j) >= 10000) {
				break;
			}
			if (func[i](j) >= 1000) {
				nums[i].push_back(func[i](j));
			}
		}
	}

	int sz = 0;
	for_each(nums.begin(), nums.end(), [&](vector <int> vi){sz += vi.size();});

	vector <Node*> adj;
	for (int i = 0; i < 6; ++i) {
		for (auto x : nums[i]) {
			adj.push_back(new Node(x, i));
		}
	}

	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			if (adj[i]->val % 100 == adj[j]->val / 100 && adj[i]->color != adj[j]->color && i != j) {
				adj[i]->edges.push_back(j);
			}
		}
	}

	bool vis[sz] = {}, tempVis[sz] = {};
	for (int i = 0; i < sz; ++i) {
		vector <int> colors(6, 0), trail;
		dfs(adj, tempVis, colors, i, i, 0, 0);
		memset(tempVis, 0, sizeof(tempVis));
	}

	return 0;
}

