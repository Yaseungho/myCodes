#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> vec;
int cnt1, cnt2, cnt3;

void paper(int startX, int startY, int length) {
	int temp = vec[startY][startX];
	if (length == 0) return;
	if (length == 1) {
		if (temp == -1) cnt1++;
		else if (temp == 0) cnt2++;
		else if (temp == 1) cnt3++;
		return;
	}
	for (int i = startY; i < (startY + length); i++) {
		for (int j = startX; j < (startX + length); j++) {
			if (vec[i][j] != temp) {
				int newlen = length / 3;
				paper(startX, startY, newlen);
				paper(startX, startY + newlen, newlen);
				paper(startX, startY + (newlen * 2), newlen);
				paper(startX + newlen, startY, newlen);
				paper(startX + newlen, startY + newlen, newlen);
				paper(startX + newlen, startY + (newlen * 2), newlen);
				paper(startX + (newlen * 2), startY, newlen);
				paper(startX + (newlen * 2), startY + newlen, newlen);
				paper(startX + (newlen * 2), startY + (newlen * 2), newlen);
				return;
			}
		}
	}
	if (temp == -1) cnt1++;
	else if (temp == 0) cnt2++;
	else if (temp == 1) cnt3++;
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		vec.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			vec[i].push_back(num);
		}
	}
	paper(0, 0, n);
	cout << cnt1 << "\n" << cnt2 << "\n" << cnt3;
	return 0;
}