//#pragma GCC optimize("03")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>

#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
#define BIGNUM 1000

typedef long long ll;

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
	if (n == 2 || n == 3) return true;

    int sqt = sqrt(n);
    
    for (int i = 2; i <= sqt; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {

    string s = "7654321"; // 1-8 and 1-9 cannot be prime since their sums are both divisible by three
	int ans;
	string::size_type sz;
	
	while (true) {
		int x = stoi(s, &sz);
		cout << x << endl;
		if (isPrime(x)) {ans = x; break;}
		prev_permutation(s.begin(), s.end());
	}

    return 0;
}
