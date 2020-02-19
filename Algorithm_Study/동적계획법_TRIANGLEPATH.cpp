#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int triangle[100][100];
int DP[100][100];
int n;

int func(int y, int x) {
	if (y == n - 1) return triangle[y][x];
	if (DP[y][x] != -1) return DP[y][x];
	return DP[y][x] = max(triangle[y][x] + func(y + 1, x), triangle[y][x] + func(y + 1, x + 1));
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		memset(triangle, -1, sizeof(triangle));
		memset(DP, -1, sizeof(DP));
		
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> triangle[i][j];
			}
		}

		cout << func(0, 0) << "\n";

	}
}