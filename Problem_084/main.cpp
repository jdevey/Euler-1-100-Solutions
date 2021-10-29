#include <bits/stdc++.h>

using namespace std;

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, pair <T1, T2> const &p) { 
    return os << '<' << p.first << ", " << p.second << '>';
}

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
void print(vector <T> values) {
	for (auto&& value : values) {
		cout << value << ' ';
	}
	cout << endl;
}

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
vector <T> multiply(vector<vector <T>> left, vector <T> right) {
	assert(left.size() == right.size());
	vector <T> product(left.size());
	for (int i = 0; i < left.size(); ++i) {
		for (int j = 0; j < left.size(); ++j) {
			product[j] += left[i][j] * right[i];
		}
	}
	return product;
}

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
vector<vector <T>> multiply(vector<vector <T>> left, vector<vector <T>> right) {
	assert(left.size() == right.size() && left[0].size() == right[0].size());
	vector<vector <T>> product(left.size(), vector<T>(left[0].size()));
	for (int i = 0; i < left.size(); ++i) {
		for (int j = 0; j < left.size(); ++j) {
			for (int k = 0; k < left.size(); ++k) {
				product[i][j] += left[i][k] * right[k][j];
			}
		}
	}
	return product;
}

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
vector <T> operator*(vector<vector <T>> left, vector <T> right) {
	return multiply(left, right);
}

vector <double> get_distribution(int dice_size) {
	vector <double> dist(2 * dice_size + 1, 0.0);
	for (int i = 2; i <= dice_size + 1; ++i) {
		dist[i] = (double)(i - 1) / dice_size / dice_size;
		dist[2 * dice_size - i + 2] = dist[i];
	}
	return dist;
}

vector<vector <double>> get_probability_matrix(int dice_size) {
	set <int> cc = {2, 17, 33}, ch = {7, 22, 36};
	map <int, int> ch_railroads = {{7, 15}, {22, 25}, {36, 5}}, ch_utilities = {{7, 12}, {22, 28}, {36, 12}};
	vector<vector <double>> mtr(40, vector<double>(40, 0.0));
	vector <double> dist = get_distribution(dice_size);
	for (int i = 0; i < 40; ++i) {
		for (int j = 2; j < dist.size(); ++j) {
			int landing = (i + j) % 40;
			double base_prob;
			if (~j & 1) {
				double jail_prob = dist[j] / pow(dice_size, 2) * dist[2] / dist[j];
				mtr[i][10] += jail_prob;
				base_prob = dist[j] - jail_prob;
			}
			else {
				base_prob = dist[j];
			}
			if (landing == 30) { // jail
				mtr[i][10] += base_prob;
			}
			else if (cc.find(landing) != cc.end()) { // community chest
				mtr[i][landing] += base_prob * 7 / 8;
				mtr[i][0] += base_prob * 1 / 16;
				mtr[i][10] += base_prob * 1 / 16;
			}
			else if (ch.find(landing) != ch.end()) { // chance
				mtr[i][landing] += base_prob * 3 / 8;
				mtr[i][0] += base_prob * 1 / 16;
				mtr[i][10] += base_prob * 1 / 16;
				mtr[i][11] += base_prob * 1 / 16;
				mtr[i][24] += base_prob * 1 / 16;
				mtr[i][39] += base_prob * 1 / 16;
				mtr[i][5] += base_prob * 1 / 16;
				mtr[i][ch_railroads[landing]] += base_prob * 1 / 8;
				mtr[i][ch_utilities[landing]] += base_prob * 1 / 16;
				mtr[i][(landing + 37) % 40] += base_prob * 1 / 16;
			}
			else {
				mtr[i][landing] += base_prob;
			}
		}
	}
	return mtr;
}

double state_vector_diff(vector <double>& a, vector <double>& b) {
	double sm = 0.0;
	for (int i = 0; i < a.size(); ++i) {
		sm += abs(a[i] - b[i]);
	}
	return sm;
}

int rand_range(int l, int r) {
	static std::random_device dev;
    static std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(l, r);
	return dist(rng);
}

vector <pair <double, string>> simulate() {
	set <int> cc = {2, 17, 33}, ch = {7, 22, 36};
	map <int, int> ch_railroads = {{7, 15}, {22, 25}, {36, 5}}, ch_utilities = {{7, 12}, {22, 28}, {36, 12}};
	vector <int> visited(40, 0);
	int total = 0, pos = 0, double_cnt = 0;
	while (total < 1e8) {
		int d1 = rand_range(1, 6), d2 = rand_range(1, 6), sm = d1 + d2;
		bool is_double = d1 == d2;
		is_double ? ++double_cnt : double_cnt = 0;
		if (double_cnt == 3) {
			double_cnt = 0;
			pos = 10;
		}
		else {
			pos = (pos + sm) % 40;
			if (pos == 30) { // jail
				pos = 10;
			}
			else if (cc.find(pos) != cc.end()) { // community chest
				int rng = rand_range(1, 16);
				if (rng == 15) {
					pos = 0;
				}
				else if (rng == 16) {
					pos = 10;
				}
			}
			else if (ch.find(pos) != ch.end()) { // chance
				int rng = rand_range(1, 16);
				if (rng == 1) {
					pos = 0;
				}
				else if (rng == 2) {
					pos = 10;
				}
				else if (rng == 3) {
					pos = 11;
				}
				else if (rng == 4) {
					pos = 24;
				}
				else if (rng == 5) {
					pos = 39;
				}
				else if (rng == 6) {
					pos = 5;
				}
				else if (rng == 7 || rng == 8) {
					pos = ch_railroads[pos];
				}
				else if (rng == 9) {
					pos = ch_utilities[pos];
				}
				else if (rng == 10) {
					pos = (pos + 37) % 40;
				}
			}
		}
		++total;
		++visited[pos];
	}
	vector <pair <double, string>> solution;
	for (int i = 0; i < 40; ++i) {
		solution.emplace_back((double)visited[i] / total, to_string(i / 10) + to_string(i % 10));
	}
	sort(solution.begin(), solution.end(), greater<>());
	return solution;
}

int main() {
	cout << fixed << setprecision(12);
	vector<vector <double>> mtr = get_probability_matrix(4);
	for (auto & v : mtr) {
		double sm = 0.0;
		for (auto& p : v) {
			sm += p;
		}
		assert(abs(sm - 1.0) < 1e-15);
	}
	vector <vector <double>> m1({{1, 2}, {3, 4}});
	vector <double> m2({5, 6});
	vector <double> state_vector(mtr.size(), 0.0), previous_state_vector = state_vector;
	state_vector[25] = 1.0;
	while (state_vector_diff(state_vector, previous_state_vector) > 1e-13) {
		previous_state_vector = state_vector;
		state_vector = multiply(mtr, state_vector);
	}
	vector <pair <double, string>> solution;
	for (int i = 0; i < state_vector.size(); ++i) {
		solution.emplace_back(state_vector[i], to_string(i / 10) + to_string(i % 10));
	}
	sort(solution.begin(), solution.end(), greater<>());
	print(solution);
	return 0;
}

