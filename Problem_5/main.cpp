#include <iostream>

using namespace std;

int main() {

//    We just need to find its prime factorization and avoid repeating primes unnecessarily.
//    2520 = 7 * 5 * 3^2 * 2^3
//
//    Now we will try to include all numbers from 11 to 20...
//
//    11: Not found in the prime factorization of 2520, so we will add it.
//    12: Equivalent to 3 * 2^2, so it is covered.
//    13: Not found in the prime factorization of 2520, so we will add it.
//    14: Equivalent to 7 * 2, so it is covered.
//    15: Equivalent to 5 * 3, so it is covered.
//    16: Equivalent to 2^4, so we will need to multiply by two.
//    17: Not found in the prime factorization of 2520, so we will add it.
//    18: Equivalent to 3^2 * 2, so it is covered.
//    19: Not found in the prime factorization of 2520, so we will add it.
//    20: Equivalent to 5 * 2^2, so it is covered.

    cout << 2520 * 11 * 13 * 2 * 17 * 19;

    return 0;
}