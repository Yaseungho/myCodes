#include <iostream>
#define MOD 10007
using namespace std;
int dp[1001][1001];

int func(int n, int k) {
	if (n < k || k < 0) return 0;
	if (dp[n][k] != -1) return dp[n][k];
	int ret = (func(n - 1, k - 1) % MOD + func(n - 1, k) % MOD) % MOD;
	dp[n][k] = ret; 
	return ret;
}

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			dp[i][j] = -1; 
		}
	}
	dp[0][0] = dp[1][0] = dp[1][1] = dp[2][2] = 1;
	dp[2][1] = 2;
	cout << func(N, K);
	return 0;
}