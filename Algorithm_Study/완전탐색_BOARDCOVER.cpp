#include <iostream>
#include <vector>
using namespace std;

int H, W;

int Dpos[4][3][2] = {
	{{0,0}, {1, 0}, {0, 1}},
	{{0,0}, {1, 0}, {1, 1}},
	{{0,0}, {1, 0}, {1,-1}},
	{{0,0}, {0, 1}, {1, 1}}
};

bool IsCanCover(int i, int sy, int sx, vector< vector <bool> >& board) {
	if (sy + Dpos[i][1][0] >= 0 &&
		sx + Dpos[i][1][1] >= 0 &&
		sy + Dpos[i][1][0] < H &&
		sx + Dpos[i][1][1] < W &&
		sy + Dpos[i][2][0] >= 0 &&
		sx + Dpos[i][2][1] >= 0 &&
		sy + Dpos[i][2][0] < H &&
		sx + Dpos[i][2][1] < W) {
		if (!board[sy + Dpos[i][0][0]][sx + Dpos[i][0][1]] &&
			!board[sy + Dpos[i][1][0]][sx + Dpos[i][1][1]] &&
			!board[sy + Dpos[i][2][0]][sx + Dpos[i][2][1]]) return true;
	}
	return false;
}

int Cover(vector< vector <bool> >& board) {
	int sx = 0, sy = 0, ret = 0;
	for (; sy < H; sy++) {
		for (sx = 0; sx < W; sx++) if (!board[sy][sx]) break;
		if (sx != W) break;
	}
	if (sy == H && sx == W) return 1;
	for (int i = 0; i < 4; i++) {
		if (IsCanCover(i, sy, sx, board)) {
			board[sy + Dpos[i][0][0]][sx + Dpos[i][0][1]] = true;
			board[sy + Dpos[i][1][0]][sx + Dpos[i][1][1]] = true;
			board[sy + Dpos[i][2][0]][sx + Dpos[i][2][1]] = true;
			ret += Cover(board);
			board[sy + Dpos[i][0][0]][sx + Dpos[i][0][1]] = false;
			board[sy + Dpos[i][1][0]][sx + Dpos[i][1][1]] = false;
			board[sy + Dpos[i][2][0]][sx + Dpos[i][2][1]] = false;
		}
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		vector< vector <bool> > board;
		int cnt = 0;
		char temp;
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			vector<bool> vec;
			board.push_back(vec);
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> temp;
				if (temp == '.') cnt++;
				board[i].push_back(temp == '#' ? true : false);
			}
		}
		if (cnt % 3 != 0) cout << "0\n";
		else {
			cout << Cover(board) << "\n";
		}
	}
}