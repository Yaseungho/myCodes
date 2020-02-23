#include <iostream>
#include <cstring>
using namespace std;

int DP[101][101];
int map[100][100];
int N;

bool jump(int y, int x) {
	if (x == N - 1 && y == N - 1) return 1;
	if (N - 1 < x || N - 1 < y) return 0;
	if (DP[y][x] != -1) return (bool)DP[y][x];
	return DP[y][x] = (jump(y + map[y][x], x) || jump(y, x + map[y][x]));
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		memset(DP, -1, sizeof(DP));
		cout << (jump(0, 0) ? "YES" : "NO") << "\n";
	}
	return 0;
}