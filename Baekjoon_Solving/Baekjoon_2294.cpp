#include <iostream>
#include <algorithm>
using namespace std;
int N;
int dp[101][10001];
int cost[101];

int func(int n, int k) {
	if (n == N) return k == 0 ? 0 : 2000000000;
	if (dp[n][k] != -1) return dp[n][k];
	int ret = func(n + 1, k);
	if (cost[n] <= k) ret = min(ret, func(n, k - cost[n]) + 1);
	dp[n][k] = ret;
	return ret;
}

int main() {
	int K, temp;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> cost[i];
	for (int i = 0; i < 101; i++) 
		for (int j = 0; j < 10001; j++) dp[i][j] = -1;
	int result = func(0, K);
	cout << (result == 2000000000 ? -1 : result);
	return 0;
}