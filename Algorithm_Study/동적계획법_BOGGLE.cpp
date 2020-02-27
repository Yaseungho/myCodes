#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

char board[5][5];
int DP[6][6][11];//DP[y][x][n] : y,x좌표에서 단어의 n번째 글자부터 시작해 연결이 가능한가?
string str;

const int dx[8] = { -1,-1,-1, 1,1,1, 0,0 };
const int dy[8] = { -1, 0, 1,-1,0,1,-1,1 };

bool hasWord(int y, int x, int num) {
	if (x < 0 || x > 4 || y < 0 || y > 4) return false;
	if (DP[y][x][num] != -1) return DP[y][x][num];
	if (num == str.size()) return true;
	bool ret = false;
	for (int i = 0; i < 8; i++) {
		if (board[y + dy[i]][x + dx[i]] == str[num] && hasWord(y + dy[i], x + dx[i], num + 1))
			ret = true;
	}
	return DP[y][x][num] = ret;
}

int main() {
	int C, N;
	cin >> C;
	while (C--) {
		vector < pair <string, bool> > vec;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> board[i][j];
			}
		}
		cin >> N;
		while (N--) {
			memset(DP, -1, sizeof(DP));
			cin >> str;
			bool result = false;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (board[i][j] == str[0]) {
						if (hasWord(i, j, 1)) result = true;
					}
				}
			}
			vec.push_back(make_pair(str, result));
		}

		for (pair<string, bool>& v : vec) {
			cout << v.first << " " << (v.second ? "YES" : "NO") << "\n";
		}

	}
	return 0;
}