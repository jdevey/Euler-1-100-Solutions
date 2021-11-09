#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MX = 12000;

pair <int, int> best_for_k(vector <int>& l) {
	int prod = 1;
	int sum = 0;
	for (auto num : l) {
		prod *= num;
		sum += num;
	}
	return {prod - sum + l.size(), prod};
}

vector <int> fill_right(vector <int>& l, int pos, int val) {
	vector <int> filled(l);
	for (int i = pos; i < filled.size(); ++i) {
		filled[i] = val;
	}
	return filled;
}

int main() {
	const int top = 2 * MX + 2;
	vector <int> best(top, INF);
	for (int sz = 2;; ++sz) {
		vector <int> elements(sz, 2);
		if (best_for_k(elements).first >= top) break;
		bool cycle_complete = false;
		while (!cycle_complete) {
			for (;; ++elements.back()) {
				pair <int, int> bk = best_for_k(elements);
				if (bk.first >= top) break;
				best[bk.first] = min(best[bk.first], bk.second);
			}
			for (int i = sz - 2; i > -1; --i) {
				auto filled = fill_right(elements, i, elements[i] + 1);
				if (best_for_k(filled).first < top) {
					elements = filled;
					break;
				}
				else if (i == 0) {
					cycle_complete = true;
					break;
				}
			}
		}
	}
	int sm = 0;
	bool found[top] = {};
	for (int i = 2; i <= MX; ++i) {
		sm += (int)!found[best[i]] * best[i];
		found[best[i]] = true;
	}
	cout << sm << endl;
	return 0;
}
