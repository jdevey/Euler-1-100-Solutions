#include <bits/stdc++.h>

using namespace std;

int get_saved(string s) {
	const static vector <pair <string, string>> m = {
		{"DCCCC", "CM"},
		{"CCCC", "CD"},
		{"LXXXX", "XC"},
		{"XXXX", "XL"},
		{"VIIII", "IX"},
		{"IIII", "IV"}
	};
	int sm = 0;
	for (auto& p : m) {
		auto f = s.find(p.first);
		if (f != string::npos) {
			s.replace(f, p.first.size(), p.second);
			sm += p.first.length() - p.second.length();
		}
	}
	return sm;
}

int main() {
	fstream fin("p089_roman.txt");
	string line;
	int sm = 0;
	while (getline(fin, line)) {
		sm += get_saved(line);
	}
	cout << sm << endl;
	return 0;
}
