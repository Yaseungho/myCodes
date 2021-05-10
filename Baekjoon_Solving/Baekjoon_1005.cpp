#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int N, K, W, cost[1001], DP[1001];//DP[n] n번째 건물을 짓는 데 걸리는 최소 시간

int solve(int n) {
	if (DP[n] != -1) return DP[n];
	int ret = 0;
	for (int i = 0; i < adj[n].size(); i++) ret = max(ret, solve(adj[n][i]));
	return DP[n] = cost[n] + ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(DP, -1, sizeof(DP));

	int T;
	cin >> T;
	while (T--) {
		adj.clear();
		memset(DP, -1, sizeof(DP));
		cin >> N >> K;
		adj.resize(N);
		for (int i = 0; i < N; i++) cin >> cost[i];
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			adj[y - 1].push_back(x - 1);
		}
		cin >> W;
		cout << solve(W - 1) << "\n";
	}
}