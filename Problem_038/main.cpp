//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define BIG 1000000007
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

using namespace std;

typedef long long ll;

string mx = "123456789";

bool isPan(string s) {
	if (s.size() != 9) return false;
	int tp[10] = {};
	int example[] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	fl (i, 10) ++tp[s[i] - '0'];
	fl (i, 10) if (tp[i] != example[i]) return false;
	return true;
}

void isGood(int n) {
	for (int i = 2; i < 10; ++i) {
		string s;
		for (int j = 1; j <= i; ++j) {
			s += to_string(j * n);
		}
		if (isPan(s) && !lexicographical_compare(s.begin(), s.end(), mx.begin(), mx.end())) mx = s;
	}
}

int main() {
	
	for (int i = 1; i < 10000; ++i) isGood(i);
	cout << mx;
	
    return 0;
}
