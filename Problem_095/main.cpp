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

int main() {
	int top = 1000001;
	int* proper = new int[top], *chain_l = new int[top];
	for (int i = 1; i <= top / 2; ++i) {
		for (int j = i * 2; j < top; j += i) {
			proper[j] += i;
		}
	}
	int max_size = 0;
	vector <int> max_chain;
	for (int i = 0; i < top; ++i) {
		vector <int> vis;
		set <int> vis_set;
		int curr = i;
		while (curr < top && chain_l[curr] == 0 && vis_set.find(curr) == vis_set.end()) {
			vis.push_back(curr);
			vis_set.insert(curr);
			curr = proper[curr];
		}
		if (curr >= top || chain_l[curr] == -1) {
			for (auto x : vis) {
				chain_l[x] = -1;
			}
		}
		else if (chain_l[curr] != -0) {
			for (auto x : vis) {
				chain_l[x] = chain_l[curr];
			}
		}
		else {
			vector <int>::iterator find_it = find(vis.begin(), vis.end(), curr);
			int chain_size = vis.end() - find_it;
			for (auto x : vis) {
				chain_l[x] = chain_size;
			}
			if (chain_size > max_size) {
				max_chain = vector(find_it, vis.end());
				max_size = chain_size;
			}
		}
	}
	cout << *min_element(max_chain.begin(), max_chain.end()) << endl;
	return 0;
}
