//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define BIG 1000000
#define fl(x,m,n) for(int (x) = (m); (x) < (n); ++(x))

using namespace std;

typedef long long ll;
typedef long double lld;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;

    int sqt = sqrt(n);

    for (int i = 2; i <= sqt; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void sieveOfEratosthenes(bool sieve[], int sz) {
    sieve[0] = true, sieve[1] = true;
    int sqt = sqrt(sz);
    fl (i, 2, sqt) {
        int ind = 2 * i;
        if (!isPrime(i)) sieve[i] = true;
        while (ind < sz) {
            sieve[ind] = true;
            ind += i;
        }
    }
}

int main() {

    bool sv[BIG] = {};
    sieveOfEratosthenes(sv, BIG);

    vector <int> primes;
    fl (i, 2, BIG) if (!sv[i]) primes.push_back(i);
    int sz = primes.size();

    ll sumArr[sz] = {};
    sumArr[0] = primes[0];
    fl (i, 1, sz) sumArr[i] = sumArr[i - 1] + primes[i];

    ll length = 1, maxPrime = 0, maxLen = 0;

    while (true) {
        int matchCount = 0;
        for (int i = 0; i < sz - length; ++i) {
            ll sum = 0;
            if (i == 0) sum = sumArr[length - 1];
            else sum = sumArr[i + length - 1] - sumArr[i - 1];
            if (sum >= BIG) break;
            if (isPrime(sum)) {
                ++matchCount;
                if (length > maxLen) {
                    maxPrime = sum;
                    maxLen = length;
                }
            }
        }
        if (length > sz * 9 / 10) break;
        ++length;
    }

    cout << maxPrime << endl;

    return 0;
}
