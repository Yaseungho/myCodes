#include <iostream>'
#define MOD 1000000000
using namespace std;
int dp[101][10];

int func(int n, int i) {
	if (n == 1) return 1;
	if (dp[n][i] != -1) return dp[n][i];
	int ret = 0;
	if (i == 0) ret = func(n - 1, i + 1) % MOD;
	if (i == 9) ret = func(n - 1, i - 1) % MOD;
	if (i != 0 && i != 9) ret = (func(n - 1, i - 1) % MOD + func(n - 1, i + 1) % MOD) % MOD;
	dp[n][i] = ret;
	return ret;
}

int main() {
	int N;
	cin >> N;
	long long result = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 10; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 1; i < 10; i++) {
		result += func(N, i);
	} result %= MOD;
	cout << result;
	return 0;
}