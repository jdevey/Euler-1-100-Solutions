#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
#define BIGNUM 1000

typedef long long ll;

using namespace std;

int main() {

    int total = 0;
    for (int i = 1; i < BIGNUM; ++i) {
        if (i % 5 == 0) total += i;
        else if (i % 3 == 0) total += i;
    }

    cout << total << endl;
    cout << 0 % 5 << endl;

    return 0;
}