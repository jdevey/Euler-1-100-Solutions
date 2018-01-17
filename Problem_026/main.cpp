//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstring>

#define BIG 1000
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

using namespace std;

typedef long long ll;

int main() {

    ifstream finz("zin.txt");

    int maxNum;
    int maxLength = 0;
    for (int i = 1; i < BIG; ++i) {
        int tp[i + 1] = {};
        int run = 1;
        int len = 0;
        while (tp[run] < 2 && run != 0) {
            ++len;
            while (run < i) run *= 10;
            run %= i;
            ++tp[run];
        }
        if (len > maxLength) {
            maxLength = len;
            maxNum = i;
        }
    }

    cout << maxNum << " " << maxLength << endl;

    return 0;
}

