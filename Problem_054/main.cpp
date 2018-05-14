#include <bits/stdc++.h>

#define BIG 1000000007

using namespace std;

bool cmpHands(pair <int, char>* a, pair <int, char>* b) {
	pair <int, int> aa[5], bb[5];
	int csa[15] = {}, csb[15] = {};
	for (int i = 0; i < 5; ++i) {
		++csa[a[i].first];
		++csb[b[i].first];
	}
	for (int i = 0; i < 5; ++i) {
		aa[i] = {csa[a[i].first], a[i].first};
		bb[i] = {csb[b[i].first], b[i].first};
	}
	sort(aa, aa + 5);
	sort(bb, bb + 5);
	for (int i = 4; i > -1; --i) {
		if (aa[i] != bb[i]) {
			return aa[i] > bb[i];
		}
	}
}

bool isOnePair(pair <int, char>* a) {
	for (int i = 1; i < 5; ++i) if (a[i].first == a[i - 1].first) return true;
	return false;
}

bool isTwoPairs(pair <int, char>* a) {
	int pairCount = 0;
	for (int i = 1; i < 5; ++i) if (a[i].first == a[i - 1].first) ++pairCount;
	return pairCount > 1;
}

bool isThreeOfAKind(pair <int, char>* a) {
	int cs[15] = {};
	for (int i = 0; i < 5; ++i) ++cs[a[i].first];
	for (int i = 2; i < 15; ++i) if (cs[i] > 2) return true;
	return false;
}

bool isStraight(pair <int, char>* a) {
	for (int i = 1; i < 5; ++i) if (a[i].first != a[i - 1].first + 1) return false;
	return true;
}

bool isFlush(pair <int, char>* a) {
	return a[0].second == a[1].second && a[0].second == a[2].second && a[0].second == a[3].second && a[0].second == a[4].second;
}

bool isFullHouse(pair <int, char>* a) {
	int cs[15] = {};
	for (int i = 0; i < 5; ++i) ++cs[a[i].first];
	bool threeFound = false, twoFound = false;
	for (int i = 2; i < 15; ++i) {
		if (cs[i] == 3) threeFound = true;
		if (cs[i] == 2) twoFound = true;
	}
	return threeFound & twoFound;
}

bool isFourOfAKind(pair <int, char>* a) {
	int cs[15] = {};
	for (int i = 0; i < 5; ++i) ++cs[a[i].first];
	for (int i = 2; i < 15; ++i) if (cs[i] > 3) return true;
	return false;
}

bool isStraightFlush(pair <int, char>* a) {
	for (int i = 1; i < 5; ++i) if (a[i].first != a[i - 1].first + 1 || a[i].second != a[0].second) return false;
	return true;
}

bool isRoyalFlush(pair <int, char>* a) {
	for (int i = 10; i < 15; ++i) if (a[i - 10].first != i) return false;
	for (int i = 1; i < 5; ++i) if (a[i].second != a[0].second) return false;
	return true;
}

bool isAWinner(pair <int, char>* a, pair <int, char>* b) {
	sort(a, a + 5);
	sort(b, b + 5);

	if (isRoyalFlush(a)) return true;
	if (isRoyalFlush(b)) return false;

	if (isStraightFlush(a) && isStraightFlush(b)) return cmpHands(a, b);
	if (isStraightFlush(a)) return true;
	if (isStraightFlush(b)) return false;

	if (isFourOfAKind(a) && isFourOfAKind(b)) return cmpHands(a, b);
	if (isFourOfAKind(a)) return true;
	if (isFourOfAKind(b)) return false;

	if (isFullHouse(a) && isFullHouse(b)) return cmpHands(a, b);
	if (isFullHouse(a)) return true;
	if (isFullHouse(b)) return false;

	if (isFlush(a) && isFlush(b)) return cmpHands(a, b);
	if (isFlush(a)) return true;
	if (isFlush(b)) return false;

	if (isStraight(a) && isStraight(b)) return cmpHands(a, b);
	if (isStraight(a)) return true;
	if (isStraight(b)) return false;

	if (isThreeOfAKind(a) && isThreeOfAKind(b)) return cmpHands(a, b);
	if (isThreeOfAKind(a)) return true;
	if (isThreeOfAKind(b)) return false;

	if (isTwoPairs(a) && isTwoPairs(b)) return cmpHands(a, b);
	if (isTwoPairs(a)) return true;
	if (isTwoPairs(b)) return false;

	if (isOnePair(a) && isOnePair(b)) return cmpHands(a, b);
	if (isOnePair(a)) return true;
	if (isOnePair(b)) return false;

	return cmpHands(a, b);
}

int main() {

	ifstream fin("poker.txt");

	int wCnt = 0;

	for (int i = 0; i < 1000; ++i) {
		pair <int, char> a[5], b[5];
		for (int j = 0; j < 5; ++j) {
			string in;
			fin >> in;
			if (in[0] >= '2' && in[0] <= '9') a[j].first = in[0] - '0';
			else for (int k = 0; k < 5; ++k) if ("TJQKA"[k] == in[0]) a[j].first = 10 + k;
			a[j].second = in[1];
		}
		for (int j = 0; j < 5; ++j) {
			string in;
			fin >> in;
			if (in[0] >= '2' && in[0] <= '9') b[j].first = in[0] - '0';
			else for (int k = 0; k < 5; ++k) if ("TJQKA"[k] == in[0]) b[j].first = 10 + k;
			b[j].second = in[1];
		}
		if (isAWinner(a, b)) ++wCnt;
	}

	cout << wCnt << endl;

	fin.close();

    return 0;
}
