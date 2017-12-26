//#pragma GCC optimize("03")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
#define BIGNUM 1000

typedef long long ll;

using namespace std;

bool isPal (string s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != s[(s.size() - 1) - i]) return false;
    }
    return true;
}

int main() {

    int maxProduct = 0;
    fl (i, BIGNUM) {
        fl (j, BIGNUM) {
            if (isPal(to_string(i * j))) {
                if (i * j > maxProduct) maxProduct = i * j;
            }
        }
    }

    cout << maxProduct;

    return 0;
}