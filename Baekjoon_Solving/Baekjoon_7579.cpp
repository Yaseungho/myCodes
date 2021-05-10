#include <bits/stdc++.h>
using namespace std;
int M, N, DP[101][10001], cost[101], val[101];
//DP[n][c] : n번째 앱부터 c이하의 비용만으로 얻을수있는 최대 메모리
int solve(int now, int c) {
	if (c < 0) return -2e9;
	if (now == N) return 0;
	if (DP[now][c] != -1) return DP[now][c];
	return DP[now][c] = max(solve(now + 1, c), val[now] + solve(now + 1, c - cost[now]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(DP, -1, sizeof(DP));
	int res = 10000;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> val[i];
	for (int i = 0; i < N; i++) cin >> cost[i];
	for (int c = 10000; c >= 0; c--) if (solve(0, c) >= M) res = c;
	cout << res << "\n";
	return 0;
}