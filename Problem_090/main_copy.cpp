#include <bits/stdc++.h>

using namespace std;

string str(int i) {
	return to_string(i / 100) + to_string(i / 10 % 10) + to_string(i % 10);
}

bool number_in_dice(char c, string& dice) {
	if (c == '6' || c == '9') {
		return dice.find('6') != string::npos || dice.find('9') != string::npos;
	}
	return dice.find(c) != string::npos;
}

bool square_in_combo(string& a, string& b, const string& sq) {
	return number_in_dice(sq[0], a) && number_in_dice(sq[1], b) || number_in_dice(sq[1], a) && number_in_dice(sq[0], b);
}

bool is_good(string& ci, string& si, string& cj, string& sj) {
	const static vector <string> squares = {"01", "04", "09", "16", "36", "49", "64"}; // 25, and 81 are already covered
	string s1 = ci + si, s2 = cj + sj;
	for (auto& sq : squares) {
		if (!square_in_combo(s1, s2, sq)) {
			return false;
		}
	}
	return true;
}

int main() {
	cout << str(432) << ' ' << str(43) << ' ' << str(3) << endl;
	string t1 = "058999", t2 = "124999", sq = "36";
//	cout << square_in_combo(t1, t2, sq) << endl;
	vector <pair <string, string>> combos = {
		{"028", "451"},
		{"021", "458"},
		{"058", "421"},
		{"051", "428"}
	};
	set <string> found;
	for (auto& combo : combos) {
		for (int i = 0; i < 1000; ++i) {
			string si = str(i);
			for (int j = 0; j < 1000; ++j) {
				string sj = str(j);
				if (is_good(combo.first, si, combo.second, sj)) {
					string d1 = combo.first + si;
					string d2 = combo.second + sj;
					sort(d1.begin(), d1.end());
					sort(d2.begin(), d2.end());
					string first = d1 < d2 ? d1 : d2;
					string second = d1 < d2 ? d2 : d1;
//					cout << first << ' ' << second << endl;
					found.insert(first + second);
				}
			}
		}
	}

	cout << found.size() << endl;

	return 0;
}
