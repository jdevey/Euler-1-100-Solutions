//#pragma GCC optimize("03")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <fstream>

#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
#define BIGNUM 20

typedef long long ll;

using namespace std;

int main() {

    ifstream finz("zin.txt");

    int aa[20][20];

    fl (i, BIGNUM) {
        fl (j, BIGNUM) {
            finz >> aa[i][j];
        }
    }

    int maxProd = 0;
    int maxArr[4];
    fl (i, BIGNUM) {
        fl (j, BIGNUM) {
            if (j > 2 && i < BIGNUM - 3) {
                int tempProd = 1;
                int tempArr[4];
                for (int k = 0; k < 4; ++k) {
                    tempProd *= aa[i + k][j - k];
                    tempArr[k] = aa[i + k][j - k];
                }
                if (tempProd > maxProd){
                    maxProd = tempProd;
                    fl (k, 4) maxArr[k] = tempArr[k];
                }
            }
            if (i < BIGNUM - 3) {
                int tempProd = 1;
                int tempArr[4];
                for (int k = 0; k < 4; ++k) {
                    tempProd *= aa[i + k][j];
                    tempArr[k] = aa[i + k][j];
                }
                if (tempProd > maxProd) {
                    maxProd = tempProd;
                    fl (k, 4) maxArr[k] = tempArr[k];
                }
            }
            if (j < BIGNUM - 3 && i < BIGNUM - 3) {
                int tempProd = 1;
                int tempArr[4];
                for (int k = 0; k < 4; ++k) {
                    tempProd *= aa[i + k][j + k];
                    tempArr[k] = aa[i + k][j + k];
                }
                if (tempProd > maxProd) {
                    maxProd = tempProd;
                    fl (k, 4) maxArr[k] = tempArr[k];
                }
            }
            if (j < BIGNUM - 3) {
                int tempProd = 1;
                int tempArr[4];
                for (int k = 0; k < 4; ++k) {
                    tempProd *= aa[i][j + k];
                    tempArr[k] = aa[i][j + k];
                }
                if (tempProd > maxProd) {
                    maxProd = tempProd;
                    fl (k, 4) maxArr[k] = tempArr[k];
                }
            }
        }
    }

    cout << maxProd << endl;
    fl (i, 4) cout << maxArr[i] << " ";

    return 0;
}