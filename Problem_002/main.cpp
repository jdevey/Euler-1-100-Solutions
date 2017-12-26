//#pragma GCC optimize("03")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
#define BIGNUM 4000000

typedef long long ll;

using namespace std;

int main() {

    int oneBefore = 1, twoBefore = 0, current, sum = 0;
    while (true) {
        current = oneBefore + twoBefore;
        twoBefore = oneBefore;
        oneBefore = current;
        if (current > BIGNUM) break;
        if (!(current & 1)) sum += current;
    }

    cout << sum;

    return 0;
}