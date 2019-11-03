#include <iostream>
using namespace std;
char board[50][50];

int eat(int num) {
	int max = 1, cnt;
	int i, j;
	for (i = 0; i < num; i++) {
		cnt = 1;
		for (j = 0; j < (num - 1); j++) {
			if (board[i][j] == board[i][j + 1]) {
				cnt++;
				if (cnt > max) max = cnt;
			}
			else cnt = 1;
		}
	}
	for (i = 0; i < num; i++) {
		cnt = 1;
		for (j = 0; j < (num - 1); j++) {
			if (board[j][i] == board[j + 1][i]) {
				cnt++;
				if (cnt > max) max = cnt;
			}
			else cnt = 1;
		}
	}
	return max;
}

int swaping(int num) {
	int i, j, max = eat(num), eatnum;
	char temp;
	for (i = 0; i < num; i++) {
		for (j = 0; j < (num - 1); j++) {
			temp = board[i][j];
			board[i][j] = board[i][j + 1];
			board[i][j + 1] = temp;
			eatnum = eat(num);
			if (max < eatnum) {
				max = eatnum;
			}
			temp = board[i][j];
			board[i][j] = board[i][j + 1];
			board[i][j + 1] = temp;
		}
	}
	for (i = 0; i < num; i++) {
		for (j = 0; j < (num - 1); j++) {
			temp = board[j][i];
			board[j][i] = board[j + 1][i];
			board[j + 1][i] = temp;
			eatnum = eat(num);
			if (max < eatnum) {
				max = eatnum;
			}
			temp = board[j][i];
			board[j][i] = board[j + 1][i];
			board[j + 1][i] = temp;
		}
	}
	return max;
}

int main() {
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	int ret = swaping(n);
	cout << ret << endl;
	return 0;
}