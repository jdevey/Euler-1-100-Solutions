#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_match(ll num, string line) {
	string num_string = to_string(num);
	int line_pos = 0;
	for (int i = 0; i < num_string.size() && line_pos < line.size(); ++i) {
		if (line[line_pos] == num_string[i]) {
			++line_pos;
		}
	}
	return line_pos == line.size();
}

bool is_match(ll num, vector <string>& lines) {
	for (auto& line : lines) {
		if (!is_match(num, line)) {
			return false;
		}
	}
	return true;
}

int main() {
	ifstream file("p079_keylog.txt");
	string line;
	vector <string> lines;
	while (getline(file, line)) {
		lines.push_back(line);
	}
	for (ll i = 0;; ++i) {
		if (is_match(i, lines)) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}

