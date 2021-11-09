#include <bits/stdc++.h>

using namespace std;

template <typename T>
void print(T value) {
    std::cout << value << endl;
}

template <typename T, typename... Args>
void print(T value, Args... values) {
    std::cout << value << ' ';
    print(values...);
}

template <typename T>
void print(vector <T> vec) {
	for (auto elem : vec) {
		cout << elem << ' ';
	}
	cout << endl;
}

vector <string> separate(string line, char separator = ',') {
	vector <string> ans;
	string value;
	for (auto it = line.begin(); it != line.end(); ++it) {
		if (*it == separator || next(it) == line.end()) {
			ans.push_back(string(value.begin() + 1, value.end() - (next(it) != line.end())));
			value.clear();
		}
		else {
			value += *it;
		}
	}
	return ans;
}

bool are_permutation(string a, string b) {
	if (a.length() != b.length()) {
		return false;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}

int apply_mapping(string word, char* mapping) {
	string res(word.size(), 0);
	for (int i = 0; i < word.size(); ++i) {
		res[i] = mapping[word[i] - 'A'];
	}
	return res[0] == '0' ? -1 : stoi(res);
}

int main() {
	freopen("p098_words.txt", "r", stdin);
	string text;
	cin >> text;
	vector <string> s(separate(text));
	vector <pair <string, string>> perm_pairs;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = i + 1; j < s.size(); ++j) {
			if (are_permutation(s[i], s[j])) {
				perm_pairs.push_back({s[i], s[j]});
			}
		}
	}
	set <int> squares_set;
	vector <int> squares;
	for (int i = 1; i * i < 1e9; ++i) {
		squares.push_back(i * i);
		squares_set.insert(i * i);
	}
	int mx = 0;
	for (auto& p : perm_pairs) {
		for (auto it = lower_bound(squares.begin(), squares.end(), pow(10, (int)p.first.length() - 1)); *it < pow(10, (int)p.first.length()) && it != squares.end(); ++it) {
			string s1 = p.first, s2 = p.second, sq = to_string(*it);
			char mapping[26] = {}, inv_map[10] = {};
			bool good_map = true;
			for (int i = 0; i < s1.length(); ++i) {
				if (inv_map[sq[i] - '0'] != 0 && inv_map[sq[i] - '0'] != s1[i]) {
					good_map = false;
					break;
				}
				mapping[s1[i] - 'A'] = sq[i];
				inv_map[sq[i] - '0'] = s1[i];
			}
			if (!good_map) {
				continue;
			}
			int applied = apply_mapping(s2, mapping);
			if (applied == -1) {
				continue;
			}
			if (squares_set.find(applied) != squares_set.end()) {
				mx = max({mx, applied, *it});
			}
		}
	}
	cout << mx << endl;
	return 0;
}
