#include <iostream>
#include <vector>
using namespace std;

bool areFriends[10][10];

int countPairings(bool taken[10], int n) {
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1) return 1;
	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken, n);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main() {
	int T, nFriends, nPairs, first, second;
	vector<int> results;
	cin >> T;
	while (T--) {
		bool taken[10] = { false };
		for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) areFriends[i][j] = false;
		cin >> nFriends >> nPairs;
		while (nPairs--) {
			cin >> first >> second;
			areFriends[first][second] = true;
			areFriends[second][first] = true;
		}
		cout << countPairings(taken, nFriends) << "\n";
	}
	return 0;
}