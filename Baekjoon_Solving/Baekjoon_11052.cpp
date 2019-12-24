#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> cost;
int N;
int dp[1000][1001];
int func(int n, int k) {
	if (n == N) return (k == 0 ? 0 : -1234567890);
	if (dp[n][k] != -1) return dp[n][k];
	int ret = func(n + 1, k);
	if (k >= n + 1) ret = max(ret, func(n, k - n - 1) + cost[n]);
	dp[n][k] = ret;
	return ret;
}

int main() {
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		cost.push_back(temp);
	}
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1001; j++) {
			dp[i][j] = -1;
		}
	}
	cout << func(0, N);
	return 0;
}