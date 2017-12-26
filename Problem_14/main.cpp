#pragma GCC optimize("03")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
#define BIGNUM 1000000

typedef long long ll;

using namespace std;

ll collatz(ll n) {
    ll count = 1;
    while (true) {
        if (n == 1) return count;
        else if (n & 1) n = 3 * n + 1;
        else n /= 2;
        ++count;
    }
}

int main() {

    ll maxCount = 0;
    ll maxInd = 0;
    for (ll i = 1; i < BIGNUM; ++i) {
        ll count = collatz(i);
        if (count > maxCount) {
            maxCount = count;
            maxInd = i;
        }
    }

    cout << maxCount << " " << maxInd;

    return 0;
}