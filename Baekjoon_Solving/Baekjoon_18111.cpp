#include <iostream>
using namespace std;
int N, M, B;
int map[501][501];

int solve(int height) {
	int time = 0;
	int blocks = 0;//필요 블럭 수
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > height) {
				blocks -= map[i][j] - height;
				time += 2 * (map[i][j] - height);
			}
			else if (map[i][j] < height) {
				blocks += height - map[i][j];
				time += height - map[i][j];
			}
		}
	}
	if (blocks > B) return 999999999;
	else return time;
}

int main() {
	int result1 = 999999999, result2 = 0;
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> map[i][j];
	for (int i = 0; i < 257; i++) {
		int temp = solve(i);
		if (temp <= result1) {
			result1 = temp;
			result2 = i;
		}
	}
	cout << result1 << " " << result2 << "\n";
}