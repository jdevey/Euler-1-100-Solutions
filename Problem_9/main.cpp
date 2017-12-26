//#pragma GCC optimize("03")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
#define BIGNUM 1000

typedef long long ll;

using namespace std;

bool isTriplet (double a, double b) {
    return sqrt(a * a + b * b) == ceil(sqrt(a * a + b * b)) ? true : false;
}

int main() {

    for (int i = 1; i <= BIGNUM; ++i) {
        for (int j = 1; j <= BIGNUM; ++j) {
            if (isTriplet((double)i, (double)j)) {
                if (i + j + sqrt(i * i + j * j) == BIGNUM) {
                    cout << i << " " << j << " " << sqrt(i * i + j * j) << endl;
                    cout << i * j * sqrt(i * i + j * j) << endl;
                }
            }
        }
    }

    return 0;
}