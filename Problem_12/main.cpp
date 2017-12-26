//#pragma GCC optimize("03")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
#define BIGNUM 500

typedef long long ll;

using namespace std;

vector <ll> factorLister(ll n) {

    vector <ll> completeList;

    double sq = sqrt(n);
        for (ll i = 1; i <= sq; ++i) {
            if (n % i == 0) {
                if (i * i == n) completeList.push_back(i); //This is the perfect-square case
                else {
                completeList.push_back(i);
                completeList.push_back(n / i);
                }
            }
        }

    return completeList;
}

/*
int factorLister(ll n) {

    int facCount = 0;

    double sq = sqrt(n);
    for (ll i = 1; i <= sq; ++i) {
        if (n % i == 0) {
            if (i * i == n) ++facCount; //This is the perfect-square case
            else {
                ++++facCount;
            }
        }
    }

    return facCount;
}
*/
int main() {

    ll index = 1;
    ll runningTri;
    while (true) {
        ++index;
        runningTri = index * (index + 1) / 2;
        //int count = factorLister(runningTri);
        vector <ll> fList = factorLister(runningTri);
        if (fList.size() > BIGNUM) {
            cout << index;
            return 0;
        }
    }

    return 0;
}