#include <bits/stdc++.h>

using namespace std;

typedef int (*polygon)(int);

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

bool isEdge(int a, int b) {
	return a / 100 == b % 100;
}

void inc(vector <vector <int>>& nums, int* pt, int layer) {
	if (pt[layer] < nums[layer].size() - 1) ++pt[layer];
	else {
		pt[layer] = 0;
		inc(nums, pt, layer - 1);
	}
}

void isCompleteUtil(vector <vector <int>>& nums, int* pt, bool* vis, bool& good, int origNum, int currNum, int depth) {
	if (depth == 5) {
		if (isEdge(currNum, origNum)) good = true;
		return;
	}
	for (int i = 1; i < 6; ++i) {
		if (!vis[i] && isEdge(currNum, nums[i][pt[i]])) {
			vis[i] = true;
			isCompleteUtil(nums, pt, vis, good, origNum, nums[i][pt[i]], depth + 1);
			break;
		}
	}
}

bool isComplete(vector <vector <int>>& nums, int* pt) {
	bool vis[6] = {}, good = false;
	vis[0] = true;
	int origNum = nums[0][pt[0]];
	isCompleteUtil(nums, pt, vis, good, origNum, origNum, 0);
	return good;
}

void printNums(vector <vector <int>>& nums, int* pt) {
	int sm = 0;
	for (int i = 0; i < 6; ++i) {
		cout << nums[i][pt[i]] << endl;
		sm += nums[i][pt[i]];
	}
	cout << "Sum: " << sm << endl << endl;
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
			int result = func[i](j);
			if (result >= 10000) break;
			if (result >= 1000) nums[i].push_back(result);
		}
	}

	int pt[6] = {}, ind = 0;
	while(true) {
		if (isComplete(nums, pt)) {
			printNums(nums, pt);
			return 0;
		}
		inc(nums, pt, 5);
		++ind;
	}
}
