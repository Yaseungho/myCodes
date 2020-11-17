#include <bits/stdc++.h>
using namespace std;
double height[200001];
vector<int> adj[200001];
int N, K;

int solve(int n, double h, int goal) {
	if (h <= 0) return 0;
	int res = 1;
	for (int i = 0; i < adj[n].size(); i++) {
		int next = adj[n][i];
		if (next != goal) res *= solve(next, 2 * h - height[next] + height[n], n);
	}
	return res;
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> height[i];
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int res = 1;
	for (int i = 0; i < adj[K].size(); i++) {
		int next = adj[K][i];
		res *= solve(next, height[K] - height[next], K);
	}
	if (res == 1) cout << "0\n";
	else cout << "1\n";
}