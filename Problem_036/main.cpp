#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define BIG 1000000
#define fl(i,n) for(int (i) = 0; (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

bool isPal(string s) {
	fl (i, s.size()) if (s[i] != s[s.size() - i - 1]) return false;
	return true;
}

bool isGood(int n) {
	int num = n;
	string s1 = to_string(num), s2;
	while (num != 0) {
		s2 += num % 2 + '0';
		num /= 2;
	}
	if (isPal(s1) && isPal(s2)) return true;
	return false;
}

int main() {

	ll sum = 0;

    fl (i, BIG) if (isGood(i)) sum += i;

	cout << sum << endl;

    return 0;
}
