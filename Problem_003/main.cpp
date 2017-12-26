#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
#define BIGNUM 600851475143

typedef long long ll;

using namespace std;

bool isPrime(ll n) {
    double sqt = sqrt(n);
    for (int i = 2; i <= sqt; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {

    double sqt = sqrt(BIGNUM);

    int maxPrime = 0;
    for (int i = 2; i <= sqt; ++i) {
        if (BIGNUM % i == 0) {
            if (isPrime(i)) {
                maxPrime = i;
            }
        }
    }

    cout << maxPrime;

    return 0;
}