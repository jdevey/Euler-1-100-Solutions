#include <bits/stdc++.h>

using namespace std;

string str(int n, int sz) {
	string s(sz, '0');
	int i = sz - 1;
	while (n) {
		s[i] = n % 10 + '0';
		n /= 10;
		--i;
	}
	return s;
}

bool number_in_dice(char c, string& dice) {
	return c == '6' || c == '9' ? dice.find('6') != string::npos || dice.find('9') != string::npos : dice.find(c) != string::npos;
}

bool square_in_combo(string& a, string& b, const string& sq) {
	return number_in_dice(sq[0], a) && number_in_dice(sq[1], b) || number_in_dice(sq[1], a) && number_in_dice(sq[0], b);
}

bool is_good(string& ci, string& si, string& cj, string& sj) {
	const static vector <string> squares = {"01", "09", "16", "36", "49", "64"};
	string s1 = ci + si, s2 = cj + sj;
	for (auto& sq : squares) {
		if (!square_in_combo(s1, s2, sq)) {
			return false;
		}
	}
	return true;
}

bool has_dup(string s) {
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size() - 1; ++i) {
		if (s[i] == s[i + 1]) {
			return true;
		}
	}
	return false;
}

int main() {
	int h = 3;
	vector <pair <string, string>> combos = {
		{"028", "451"},
		{"021", "458"},
		{"058", "421"},
		{"051", "428"}
	};
	set <string> found;
	for (auto& combo : combos) {
		for (int i = 0; i < pow(10, h); ++i) {
			string si = str(i, h);
			string d1 = combo.first + si;
			if (has_dup(d1)) {
				continue;
			}
			for (int j = 0; j < pow(10, h); ++j) {
				string sj = str(j, h);
				string d2 = combo.second + sj;
				if (has_dup(d2)) {
					continue;
				}
				if (is_good(combo.first, si, combo.second, sj)) {
					sort(d1.begin(), d1.end());
					sort(d2.begin(), d2.end());
					string first = d1 < d2 ? d1 : d2;
					string second = d1 < d2 ? d2 : d1;
					found.insert(first + second);
				}
			}
		}
	}
	cout << found.size() << endl;
	return 0;
}
