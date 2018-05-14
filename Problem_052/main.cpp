#include <bits/stdc++.h>

#define GOAL 6

using namespace std;

bool isGood(int n) {
    bool cs[10] = {};
    int cpy = n;
    while (cpy) {
        cs[cpy % 10] = true;
        cpy /= 10;
    }
    for (int i = 2; i <= GOAL; ++i) {
        int x = n * i;
        bool cmp[10] = {};
        while(x) {
            cmp[x % 10] = true;
            x /= 10;
        }
        bool ig = true;
        for (int j = 0; j < 10; ++j) {
            if (cmp[j] != cs[j]) {
                ig = false;
                break;
            }
        }
        if (!ig) break;
        if (i == GOAL) return true;
    }
    return false;
}

int main() {
    
    int i = 1;
    while (true) {
        if (isGood(i)) {
            cout << i << endl;
            break;
        }
        ++i;
    }
    
    return 0;
}
