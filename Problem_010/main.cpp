//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#define ll long long
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
#define BIGNUM 2000000

using namespace std;

bool isPrime(int n) {
    if (n == 1) return false;

    int sqt = sqrt(n);

    for (int i = 2; i <= sqt; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {

    ll sum = 0;
    for (int i = 2; i < BIGNUM; ++i) {
        if (isPrime(i)) sum += i;
    }

    cout << sum;

    return 0;
}