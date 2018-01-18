//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define BIG 200
#define SZ 8
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

int vals[] = {200, 100, 50, 20, 10, 5, 2, 1};
int freq[] = {1, 2, 4, 10, 20, 40, 100, 200};
//int vals[] = {20, 10, 5, 2, 1};
//int freq[] = {1, 2, 4, 10, 20};

bool isNum(const int* a) {
	int sum = 0;
	fl (i, SZ) sum += a[i] * vals[i];
	if (sum == BIG) return true;
	return false;
}

int permute() {
	ll counter = 100000;
	int sum = 1;
	int a[SZ] = {};
	while (a[0] < 1) {
		if (isNum(a)) ++sum;
		for (int i = SZ - 1; i > -1; --i) {
			++a[i];
			if (a[i] > freq[i]) {
				a[i] = 0;
			}
			else break;
		}
		++counter;
	}
	return sum;
}

int main() {
	
	cout << permute();
	
    return 0;
}
