#include <iostream>
using namespace std;
int Dx[4] = {0,	0, 1,-1};
int Dy[4] = {1,-1, 0, 0};
int DP[501][501];
int Map[501][501];
int H, W;
int func(int x, int y) {
	if (x == W && y == H) return 1;
	if (DP[y][x] != -1) return DP[y][x];
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		if (x + Dx[i] < 1 || y + Dy[i] < 1 || x + Dx[i] > W || y + Dy[i] > H) continue;
		if (Map[y][x] > Map[y + Dy[i]][x + Dx[i]]) ret += func(x + Dx[i], y + Dy[i]);
	}
	return DP[y][x] = ret;
}
int main() {
	int val;
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> val;
			Map[i][j] = val;
		}
	}
	for (int i = 1; i <= H; i++) for (int j = 1; j <= W; j++) DP[i][j] = -1;
	cout << func(1, 1);
	return 0;
}