/*
l1 = sqrt(a^2 + n^2)
l2 = sqrt((b - n)^2 + c^2)
d = sqrt(a^2 + n^2) + sqrt((b - n)^2 + c^2)
d' = 1/2 * (a^2 + n^2) ^ (-1/2) * (2n) + 1/2 * (n^2 - 2 * b * n + b^2 + c^2) ^ (-1/2) * (-2 * b + 2n)
= 2n/(2 * sqrt(a^2 + n^2)) + (-2b + 2n) / (2 * sqrt(n^2 - 2bn + b^2 + c^2))
= n/sqrt(a^2 + n^2) + (n - b) / sqrt((b - n)^2 + c^2)

solve:
n/sqrt(a^2 + n^2) = (b - n) / sqrt((b - n)^2 + c^2)
n * sqrt((b - n)^2 + c^2) = (b - n) * sqrt(a^2 + n^2)
n^2 * ((b - n)^2 + c^2) = (b - n)^2 * (a^2 + n^2) (square both sides)
n^2 * (b^2 - 2bn + n^2 + c^2) = (b^2 - 2bn + n^2) * (a^2 + n^2) (expand)
b^2n^2 - 2bn^3 + n^4 + c^2n^2 = a^2b^2 - 2ba^2n + a^2n^2 + b^2n^2 - 2bn^3 + n^4 (expand)
c^2n^2 = a^2b^2 - 2ba^2n + a^2n^2 (cancel)
(a^2-c^2)n^2 - 2ba^2n + a^2b^2 = 0

quadratic:
n = (2a^2b +- sqrt(4a^4b^2 - 4 * (a^2-c^2) * a^2b^2)) / 2(a^2-c^2)
= (2a^2b +- sqrt(4a^4b^2 - 4a^4b^2 + 4a^2b^2c^2)) / 2(a^2-c^2)
= (2a^2b +- sqrt(4a^2b^2c^2)) / 2(a^2-c^2)
= (2a^2b +- 2abc) / 2(a^2-c^2)

for +:
= (2a^2b + 2abc) / 2(a^2-c^2)
= 2ab(a + c) / 2(a^2-c^2)
= 2ab(a + c) / 2(a - c)(a + c)
= 2ab / 2(a - c)
= ab / (a - c)

for -:
= (2a^2b - 2abc) / 2(a^2-c^2)
= 2ab(a - c) / 2(a^2-c^2)
= 2ab(a - c) / 2(a - c)(a + c)
= 2ab / 2(a + c)
= ab / (a + c) (local minimum)

def cuboid_route_length(a, b, c):
	p = a * b / (a + c)
	return math.sqrt(a * a + p * p) + math.sqrt(c * c + (b - p) * (b - p))
*/

#include <bits/stdc++.h>

using namespace std;

double cuboid_route_length(double a, double b, double c) {
	double p = a * b / (a + c);
	return sqrt(a * a + p * p) + sqrt(c * c + (b - p) * (b - p));
}

pair <double, bool> compute_route(double a, double b, double c) {
	double l = cuboid_route_length(a, b, c);
	return {l, abs(l - round(l)) < 1e-6};
}

bool is_integral_combination(double a, double b, double c) {
	return min({compute_route(a, b, c), compute_route(b, a, c), compute_route(a, c, b)}).second;
}

int main() {
	ios_base::sync_with_stdio(false);
	int sm = 0;
	for (int i = 1;; ++i) {
		for (int j = 1; j <= i; ++j) {
			for (int k = 1; k <= j; ++k) {
				bool is_integral_min = is_integral_combination(i, j, k);
				if (is_integral_min) {
					++sm;
					if (sm == 1000000) {
						cout << i << endl;
						return 0;
					}
				}
			}
		}
		cout << i << ' ' << sm << endl;
	}
	return 0;
}
