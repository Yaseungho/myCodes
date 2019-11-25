#include <iostream>
#include <algorithm>
using namespace std;
int N;
int value[2][100000], dp[3][100000];

int sticker(int c, int status) {
	if (c == N) return 0;
	if (dp[status][c] != -1) return dp[status][c];

	int result = sticker(c + 1, 0);
	if (status != 1) result = max(result, sticker(c + 1, 1) + value[0][c]);
	if (status != 2) result = max(result, sticker(c + 1, 2) + value[1][c]);

	return dp[status][c] = result;
}

int main() {
	int T;
	cin >> T;
	while (T--) {

		cin >> N;
		
		for (int i = 0; i < 2; i++) 
			for (int j = 0; j < N; j++) cin >> value[i][j];

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < N; j++) dp[i][j] = -1;

		cout << sticker(0, 0) << "\n";

	}
	return 0;
}