//#pragma GCC optimize("03")

//Not 104743?

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
#define BIGNUM 5

typedef long long ll;

using namespace std;

ll isPrime (ll n) {
    ll sqt = sqrt(n);
    for (int i = 2; i <= sqt; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {

    int primeCount = 0;
    ll index = 1;
    while (primeCount < BIGNUM) {
        ++index;
        if (isPrime(index)) ++primeCount;
    }

    cout << index;

    return 0;
}