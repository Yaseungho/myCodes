#include <iostream>
#include <vector>
using namespace std;
long long dp[91][2];
long long func(long long n, long long num) {
	if (n == 1) return 1;
	if (dp[n][num] != -1) return dp[n][num];
	long long ret;
	if (num) ret = func(n - 1, 0);
	else ret = func(n - 1, 0) + func(n - 1, 1);
	dp[n][num] = ret;
	return ret;
}

int main() {
	long long N;
	cin >> N;
	for (long long i = 0; i < 91; i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	cout << func(N, 1);
	return 0;
}