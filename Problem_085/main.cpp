#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <typename T>
void print(T value) {
    std::cout << value << endl;
}

template <typename T, typename... Args>
void print(T value, Args... values) {
    std::cout << value << ' ';
    print(values...);
}

ll tri(ll n) {
	return n * (n + 1) / 2;
}

double inv_tri(double n) {
	return (sqrt(8 * n + 1) - 1) / 2;
}

int main() {
	ll best = 1e9, area = 0;
	const ll GOAL = 2000000;
	for (ll n = 1; n < 50; ++n) {
		ll triangle = tri(n);
		double guess = inv_tri(GOAL / triangle);
		ll upper = ceil(guess); // lower bound checked by previous iteration
		ll upper_solution = tri(upper) * triangle;
		best = abs(GOAL - upper_solution) < abs(GOAL - best) ? (area = n * upper, upper_solution) : best;
	}
	print(best, area);
	return 0;
}

