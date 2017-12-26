//#pragma GCC optimize("03")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
#define BIGNUM 1000

typedef long long ll;

using namespace std;

int main() {

    ifstream finz("zin.txt");

    string inputString;

    char ch;
    while (finz.get(ch)) {
        if (ch < 58 && ch > 47) inputString += ch;
    }

    ll maxProduct = 0;
    int maxArray[13];
    fl (i, inputString.size() - 13) {
        ll tempProduct = 1;
        int tempArray[13];
        for (int j = i; j < i + 13; ++j) {
            //char* temp;
            //tempProduct += strtoll((char*)inputString[j], &temp, 10);
            char b = inputString[j];
            tempArray[j - i] = b - '0';
            tempProduct *= (b - '0');
        }
        if (tempProduct > maxProduct) {
            maxProduct = tempProduct;
            fl (k, 13) maxArray[k] = tempArray[k];
        }
    }

    cout << maxProduct << endl;
    fl (i, 13) cout << maxArray[i] << " ";

    return 0;
}