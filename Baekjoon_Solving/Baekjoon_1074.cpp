#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int r, c, cnt, result;
bool is = false;
void Z(int startX, int startY, int length) {
	if (is) return;
	if (length == 2) {
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				if (startY + i == r && startX + j == c) {
					cout << cnt;
					is = true;
				}
				cnt++;
			}
		}
	}
	else {
		length /= 2;
		int mx = startX + length;
		int my = startY + length;
		if (r < my) {
			if (c < mx) Z(startX, startY, length);
			cnt += (length * length);
			if (mx <= c) Z(startX + length, startY, length);
		}
		cnt += (2 * length * length);
		if(my <= r) {
			if (c < mx) Z(startX, startY + length, length);
			cnt += (length * length);
			if (mx <= c) Z(startX + length, startY + length, length);
		}
	}
	return;
}

int main() {
	int N;
	cin >> N >> r >> c;
	int n = (int)pow(2, N);
	Z(0, 0, n);
	return 0;
}