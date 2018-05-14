#include <bits/stdc++.h>

#define START 56000
#define BIG 1000000
#define ARRMAX 100000000

using namespace std;

void eratosthenes(int* a) {
    for (int i = 2; i < ARRMAX; ++i) for (int j = a[i] ? ARRMAX : 2 * i; j < ARRMAX; j += i) a[j] = true;
}

bool isGood(int* a, int n, int& ans) {
    string s = to_string(n);
    for (int i = 0; i < s.size() - 2; ++i) {
        if (s[i] <= '2' && s[i] >= '0') {
            for (int j = i + 1; j < s.size() - 1; ++j) {
                if (s[j] == s[i]) {
                    for (int k = j + 1; k < s.size(); ++k) {
                        if (s[k] == s[i]) {
                            int pCount = 0;
                            string cpy = s;
                            for (char c = s[i]; c < 58; ++c) {
                                cpy[i] = c;
                                cpy[j] = c;
                                cpy[k] = c;
                                int num = stoi(cpy);
                                if (!a[num]) ++pCount;
                            }
                            if (pCount >= 8) {
                                ans = stoi(s);
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    
    int* a = new int[ARRMAX];
    memset(a, 0, sizeof(a));
    eratosthenes(a);
    
    int ans = -1;
    for (int i = START; i < BIG; ++i) if (isGood(a, i, ans)) break;
    
    cout << ans << endl;
    
    return 0;
}
