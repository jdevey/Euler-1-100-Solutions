//#pragma GCC optimize("03")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
#define BIGNUM 100

typedef long long ll;

using namespace std;

ll sumOfSquares(ll n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

ll squareOfSum(ll n) {
    return (n * (n + 1) / 2) * (n * (n + 1) / 2);
}

int main() {

    cout << squareOfSum(BIGNUM) - sumOfSquares(BIGNUM);

    return 0;
}