#include <iostream>'
#define MOD 10007
using namespace std;
int dp[1001][11];

int func(int n, int i) {
	if (n == 1) return 1;
	if (dp[n][i] != -1) return dp[n][i];
	long long ret = 0;
	for (int temp = i; temp <= 9; temp++) {
		ret += func(n - 1, temp) % MOD;
	} ret %= MOD;
	dp[n][i] = ret;
	return ret;
}

int main() {
	int N;
	cin >> N;
	long long result = 0;
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 10; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < 10; i++) {
		result += func(N, i);
	} result %= MOD;
	cout << result;
	return 0;
}