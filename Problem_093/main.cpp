#include <bits/stdc++.h>

#define INDETERMINATE 1e9

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

vector<int> process_perm(vector <int> p) {
	for (int i = 0; i < p.size(); ++i) {
		for (int j = i + 1; j < p.size(); ++j) {
			if (p[j] > p[i]) {
				--p[j];
			}
		}
	}
	return p;
}

string process_op_ind(int op_ind) {
	const static string ops = "+-*/";
	string result;
	while (result.length() < 3) {
		result = ops[op_ind % 4] + result;
		op_ind /= 4;
	}
	return result;
}

vector <int> apply_permutation(vector <int> v, vector <int> perm) {
	vector <int> after(v.size());
	for (int i = 0; i < v.size(); ++i) {
		after[i] = v[perm[i]];
	}
	return after;
}

bool is_whole(float f) {
	return abs(round(f) - f) < 1e-4;
}

float perform(float a, float b, char op) {
	if (op == '/' && b == 0) {
		return INDETERMINATE;
	}
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			return INDETERMINATE;
	}
}

int get_result(vector <int> nums_int, string ops, vector <int> op_perm) {
	vector <float> nums;
	for (int i = 0; i < nums_int.size(); ++i) {
		nums.push_back(nums_int[i]);
	}
	for (int i = 0; i < op_perm.size(); ++i) {
		float result = perform(nums[op_perm[i]], nums[op_perm[i] + 1], ops[op_perm[i]]);
		if (result == INDETERMINATE) {
			return -1;
		}
		nums.erase(nums.begin() + op_perm[i], nums.begin() + op_perm[i] + 2);
		nums.insert(nums.begin() + op_perm[i], result);
		ops.erase(ops.begin() + op_perm[i]);
	}
	assert(nums.size() == 1);
	return is_whole(nums.front()) && nums.front() > 0 ? round(nums.front()) : -1;
}

int main() {
	bool found[3025] = {}; // 9 * 8 * 7 * 6 + 1
	int best_streak = 0;
	vector <int> best_set;
	for (int a = 1; a < 7; ++a) {
		for (int b = a + 1; b < 8; ++b) {
			for (int c = b + 1; c < 9; ++c) {
				for (int d = c + 1; d < 10; ++d) {
					vector <int> num_perm({0, 1, 2, 3});
					do {
						auto applied = apply_permutation({a, b, c, d}, num_perm);
						for (int op_ind = 0; op_ind < pow(4, 3); ++op_ind) {
							string ops = process_op_ind(op_ind);
							vector <int> op_perm({0, 1, 2});
							do {
								auto processed = process_perm(op_perm);
								int result = get_result(applied, ops, processed);
								if (result != -1) {
									found[result] = true;
								}
							} while (next_permutation(op_perm.begin(), op_perm.end()));
						}
					} while (next_permutation(num_perm.begin(), num_perm.end()));
					int streak = 0;
					for (int i = 1; found[i]; ++i, ++streak);
					if (streak > best_streak) {
						best_streak = streak;
						best_set = vector({a, b, c, d});
					}
					memset(found, 0, sizeof(found));
				}
			}
		}
	}
	cout << best_streak << endl;
	print(best_set);
	return 0;
}
