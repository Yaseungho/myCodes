#include <bits/stdc++.h>
using namespace std;
bool board[51][51]; //B´Â 0, W´Â 1

int draw(int x, int y) {
	int i, j, cnt = 0;
	for (i = y; i < y + 8; i++) {
		for (j = x; j < x + 8; j++) {
			if ((i % 2) == (j % 2) && board[i][j]) cnt++;
			else if ((i % 2) != (j % 2) && !board[i][j]) cnt++;
		}
	}
	return cnt;
}

int main() {
	int N, M, res = 1e9;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char ch;
			cin >> ch;
			board[i][j] = (ch == 'B' ? true : false);
		}
	}
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			res = min(res, draw(j, i));
			res = min(res, 64 - draw(j, i));
		}
	}
	cout << res << "\n";
}