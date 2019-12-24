#include <iostream>
#include <algorithm>
using namespace std;
int item[100][2]; //0 : 무게		1 : 가치
int dp[101][100001];
int N;

int func(int i, int k) {
	if (N == i) return 0;
	if (dp[i][k] != -1) return dp[i][k];
	int ret = func(i + 1, k);
	if (k - item[i][0] >= 0) ret = max(ret, (item[i][1] + func(i + 1, k - item[i][0])));

	dp[i][k] = ret;
	return ret;
}

int main() {
	int K, W, V;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> W >> V;
		item[i][0] = W;
		item[i][1] = V;
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][j] = -1;
		}
	}
	cout << func(0, K);
	return 0;
}