//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define BIG 1000000007
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

using namespace std;

typedef long long ll;

void adder(char* s, ll& sum) {
    int tenPow = 9;
    for (int i = 0; i < 10; ++i) {
        sum += (s[i] - '0') * pow(10, tenPow);
        --tenPow;
    }
}

bool isGood(char* s) {
    if (!(s[0] > 47 && s[0] < 58)) return false;
    int targets[] = {2, 3, 5, 7, 11, 13, 17};
    bool good = true;
    for (int i = 1; i < 8; ++i) {
        ll num = 0;
        int tenPow = 2;
        for (int j = i; j < i + 3; ++j) {
            num += (s[j] - '0') * pow(10, tenPow);
            --tenPow;
        }
        if (num % targets[i - 1] != 0) good = false;
    }
    return good;
}

void swp(char& a, char& b) {
    char tmp = a;
    a = b;
    b = tmp;
}

//Cycles through every permutation of an array. A cout statement signifies a point where one would want to record a new permutation.
void heap(char* s, int n, int len, ll& sum) {
    for (int i = 0; ; ++i) {
        if (n > 2) heap(s, n - 1, len, sum);
        if (i == n - 1) break;
        if (~n & 1) swp(s[i], s[n - 1]);
        else swp(s[0], s[n - 1]);
        if (isGood(s)) adder(s, sum);
    }
}

int main() {

    ll sum = 0;
    char s[] = "0123456789";
    int sz = 10;
    heap(s, sz, sz, sum);

    cout << sum;

    return 0;
}
