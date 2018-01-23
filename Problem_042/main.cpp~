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

bool isTriangle(int n) {
	long double result = (-1 + sqrt(1 + 8 * n)) / 2; //Quadratic formula
	return result == floor(result) ? true : false;
}

int findValue(string s) {
	int sum = 0;
	fl (i, s.size()) sum += s[i] - 'A' + 1;
	return sum;
}

int main() {

	vector <string> words;
	
	ifstream fin("words.txt");

	while (!fin.eof()) {
		string s;
		fin >> s;
		words.push_back(s);
	}

	words.pop_back();

	int count = 0;
	fl (i, words.size()) if (isTriangle(findValue(words[i]))) ++count;

	cout << count;
	
    return 0;
}
