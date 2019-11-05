#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> board; //B´Â 0, W´Â 1

int draw(int posX, int posY, bool is) {
	int i, j, cnt = 0;
	for (i = posY; i < posY + 8; i++) {
		for (j = posX; j < posX + 8; j++) {
			if (is == true) {
				if ((i % 2) == (j % 2)) {
					if (board[i][j]) {
						cnt++;
					}
				}
				else {
					if (!board[i][j]) {
						cnt++;
					}
				}
			}
			else {
				if ((i % 2) != (j % 2)) {
					if (board[i][j]) {
						cnt++;
					}
				}
				else {
					if (!board[i][j]) {
						cnt++;
					}
				}
			}
		}
	}
	return cnt;
}

int find(int H, int W) {
	int i, j, min = 99999999;
	for (i = 0; i < H - 7; i++) {
		for (j = 0; j < W - 7; j++) {
			int drawNum = draw(j, i, true);
			if (drawNum < min) {
				min = drawNum;
			}
			drawNum = draw(j, i, false);
			if (drawNum < min) {
				min = drawNum;
			}
		}
	}
	return min;
}

int main() {
	int N, M;
	char ch;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<bool> temp;
		board.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ch;
			board[i].push_back((ch == 'B' ? true : false));
		}
	}
	int out = find(N, M);
	cout << out;
	return 0;
}