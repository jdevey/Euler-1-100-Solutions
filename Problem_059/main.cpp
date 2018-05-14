#include <bits/stdc++.h>

using namespace std;

long double freq[26] =
{
8.167, // a
1.492, // b
2.782, // c
4.253, // etc...
12.702,
2.228,
2.015,
6.094,
6.966,
0.153,
0.772,
4.025,
2.406,
6.749,
7.507,
1.929,
0.095,
5.987,
6.327,
9.056,
2.758,
0.978,
2.360,
0.150,
1.974,
0.074
};

int sumAscii(string orig, string key) {
	int sm = 0;
	for (int i = 0; i < orig.size(); ++i) {
		sm += (int)orig[i] ^ key[i % 3];
	}
	return sm;
}

void printRes(string orig, string key) {
	for (int i = 0; i < orig.size(); ++i) {
		printf("%c", (int)orig[i] ^ key[i % 3]);
	}
	printf("\n");
}

long double freqDiff(long double* relative) {
	long double sm = 0.0;
	for (int i = 0; i < 26; ++i) {
		sm += abs(relative[i] - freq[i]);
	}
	return sm;
}

int countLetters(string orig, string key) {
	int sm = 0;
	for (int i = 0; i < orig.size(); ++i) {
		int c = (int)orig[i] ^ key[i % 3];
		if (c >= 'a' && c <= 'z') ++sm;
	}
	return sm;
}

void countOcc(int* occ, string orig, string key) {
	memset(occ, 0, sizeof(occ));
	for (int i = 0; i < orig.size(); ++i) {
		int c = (int)orig[i] ^ key[i % 3];
		if (c >= 'a' && c <= 'z') ++occ[c - 'a'];
	}
}

long double calcScore(string orig, string key) {
	int occ[26];
	countOcc(occ, orig, key);
	int letCount = countLetters(orig, key);

	long double relative[26];
	for (int i = 0; i < 26; ++i) {
		relative[i] = occ[i] * 100.0 / letCount;
	}

	return freqDiff(relative);
}

int main() {

	ifstream f("cipher.txt");

	string orig;
	int in;
	while (f >> in) {
		orig += (char)in;
	}

	long double minScore = 1e9;
	string bestKey;

	for (int i = 0; i < 17576; ++i) {
		string key = {(char)('a' + i / 26 / 26), (char)('a' + i / 26 % 26), (char)('a' + i % 26)};
		long double score = calcScore(orig, key);
		if (score < minScore) {
			minScore = score;
			bestKey = key;
		}
	}

	printRes(orig, bestKey);
	cout << endl << bestKey << " " << minScore << " " << sumAscii(orig, bestKey) << endl;

	f.close();

    return 0;
}
