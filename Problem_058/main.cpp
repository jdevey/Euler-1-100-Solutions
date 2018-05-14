#include <bits/stdc++.h>

#define ARRMAX 200000000

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

	for (int width = 3;; width += 2, total += 4) {
		for (int j = 1; j <= 4; ++j) {
			int val = (width - 2) * (width - 2) + ((width - 1) * j);
			if (isPrime(val)) ++pCount;
		}
		if (pCount * 10 < total) {
			cout << width << endl;
			return 0;
		}
	}

    return 0;
}
