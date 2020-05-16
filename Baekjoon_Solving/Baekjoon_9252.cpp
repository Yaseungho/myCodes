#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
string LCS;
string a, b;
int DP[1001][1001]; //DP[N][M] : 1번째 문장에서 N번째단어, 2번째 문장에서 M번째 단어까지 고려한 상태에서 최장 부분수열 길이

int func(int ind1, int ind2) {
	if (ind1 == a.size() || ind2 == b.size()) return 0;
	if (DP[ind1][ind2] != -1) return DP[ind1][ind2];
	int ret = 0;
	if (a[ind1] == b[ind2]) ret = 1 + func(ind1 + 1, ind2 + 1);
	else ret = max(func(ind1 + 1, ind2), func(ind1, ind2 + 1));
	return DP[ind1][ind2] = ret;
}

int main() {
	memset(DP, -1, sizeof(DP));
	cin >> a >> b;
	
	int ans = func(0, 0);
	if (ans == 0) {
		cout << "0\n";
	}
	else {
		int i = 0, j = 0;
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 1001; j++) {
				if (DP[i][j] == -1) DP[i][j] = 0;
			}
		}
		while (DP[i][j] != 0) {
			if (DP[i][j] == DP[i][j + 1]) j++;
			else if (DP[i][j] == DP[i + 1][j]) i++;
			else if (DP[i][j] - 1 == DP[i + 1][j + 1]) {
				LCS.push_back(a[i++]);
				j++;
			}
		}
		cout << ans<< "\n" << LCS << "\n";
	}
}