#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> cost;
int dp[316][100001];
int N;
int func(int n, int k) {
	if (n == N) return (k == 0 ? 0 : 1234567890);
	if (dp[n][k] != -1) return dp[n][k];
	int ret = func(n + 1, k);
	if (k >= cost[n]) ret = min(ret, func(n, k - cost[n]) + 1);
	dp[n][k] = ret;
	return ret;
}

int main() {
	int k;
	cin >> k;
	for (int i = 1; i * i <= k; i++) {
		cost.push_back(i * i);
	}
	reverse(cost.begin(), cost.end());
	N = (int)cost.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 100001; j++) {
			dp[i][j] = -1;
		}
	}

	cout << func(0, k);
	return 0;
}