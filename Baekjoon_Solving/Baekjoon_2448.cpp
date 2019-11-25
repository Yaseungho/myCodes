#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> vec;
void draw(int sx, int sy, int ex, int ey) {
	int h =  ey - sy;
	int h2 = ex - sx;
	if (h == 3 && h2 == 5) {
		vec[sy][sx + 2] = 1;
		vec[sy + 1][sx + 1] = 1;
		vec[sy + 1][sx + 3] = 1;
		for (int i = 0; i < 5; i++) vec[sy + 2][sx + i] = 1;
	}
	else {
		h /= 2;
		draw(sx + h, sy, sx + h * 3 - 1, sy + h);
		draw(sx, sy + h, sx + h * 2 - 1, sy + h * 2);
		draw(sx + h * 2, sy + h, sx + h * 4 - 1, sy + h * 2);
	}
	return;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<bool> temp;
		vec.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (N * 2 - 1); j++) {
			vec[i].push_back(0);
		}
	}
	draw(0, 0, (N * 2 - 1), N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (N * 2 - 1); j++) {
			cout << (vec[i][j] ? "*" : " ");
		} cout << "\n";
	}
	return 0;
}