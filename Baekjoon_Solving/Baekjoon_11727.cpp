#include <iostream>
#define MOD 10007
using namespace std;
int dp[1001];

int func(int n) {
	if (n == 1) return 1;
	if (n == 2) return 3;
	if (dp[n] != 0) return dp[n];
	int ret = (func(n - 1) % MOD + (2 * func(n - 2)) % MOD) % MOD;
	dp[n] = ret;
	return ret;
}

int main() {
	int N;
	cin >> N;
	cout << func(N);
	return 0;
}