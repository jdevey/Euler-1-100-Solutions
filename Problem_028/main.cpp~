//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define BIG 1002001
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

int main() {
	
	ll sum = 1;
	int skip = 2, sq = 3;
	for (int i = 2; i <= BIG; ++i) {
		if (i % skip == 1) sum += i;
		if (i == sq * sq) {
			sq += 2;
			skip += 2;
		}
	}

	cout << sum;
	
    return 0;
}
