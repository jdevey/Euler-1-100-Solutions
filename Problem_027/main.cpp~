//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define BIG 1000
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

using namespace std;

typedef long long ll;

bool isPrime(int n) {
    if (n < 2) return false;

    int sqt = sqrt(n);
    
    for (int i = 2; i <= sqt; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int formula(int a, int b, int n) {
	return n * n + a * n + b;
}

int main() {

	int numPrime = 0, a = 0, b = 0;
	
	for (int i = -BIG + 1; i < BIG; ++i) {
		for (int j = -BIG; j < BIG + 1; ++j) {
			int x = 0;
			while (isPrime(formula(i, j, x))) ++x;
			if (x > numPrime) {
				numPrime = x;
				a = i;
				b = j;
			}
		}
	}

	cout << a << " " << b << endl;
	cout << a * b << endl;
	cout << numPrime << endl;
	
    return 0;
}
