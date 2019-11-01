#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int coverType[4][3][2] = {
	{{ 0, 0},{ 1, 0},{ 0, 1}},
	{{ 0, 0},{ 0, 1},{ 1, 1}},
	{{ 0, 0},{ 1, 0},{ 1, 1}},
	{{ 0, 0},{ 1, 0},{ 1,-1}}
};

bool set(vector<vector<int>>& board, int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[i].size()) ok = false;
		else if ((board[ny][nx] += delta) > 1) ok = false;
	}
	return ok;
}

int cover(vector<vector<int>>& board) {
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		if (set(board, y, x, type, 1)) ret += cover(board);
		set(board, y, x, type, -1);
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		vector< vector<int> > board;
		int height, width, sum = 0;
		cin >> height >> width;
		for (int i = 0; i < height; i++) {
			vector<int> element;
			board.push_back(element);
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				char num;
				cin >> num;
				if(num == '#') board[i].push_back(1);
				else if (num == '.') {
					board[i].push_back(0);
					sum++;
				}
			}
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cout << board[i][j] << " ";
			} cout << "\n";
		}
		cout << (sum % 3 ? 0 : cover(board)) << "\n";
	}
}