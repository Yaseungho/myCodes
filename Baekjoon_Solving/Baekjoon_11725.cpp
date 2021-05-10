#include <bits/stdc++.h>
using namespace std;
vector< vector< int >> adj;
int res[100001];
bool vit[100001];

void dfs(int now) {
	vit[now] = true;
	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i];
		if (!vit[next]) {
			res[next] = now;
			dfs(next);
		}
	}
}

int main() {
	int N, V, E;
	cin >> N;
	adj.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		cin >> V >> E;
		adj[V].push_back(E);
		adj[E].push_back(V);
	}
	dfs(1);
	for (int i = 2; i <= N; i++) cout << res[i] << "\n";
	return 0;
}