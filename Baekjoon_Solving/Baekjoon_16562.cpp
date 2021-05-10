#include <bits/stdc++.h>
using namespace std;
int N, M, k, tree[10001], cost[10001], mincost[10001];

int find(int n) {
	if (tree[n] < 0) return n;
	tree[n] = find(tree[n]);
	return tree[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	tree[b] = a;
}

int main() {
	int res = 0;
	cin >> N >> M >> k;
	for (int i = 1; i <= N; i++) {
		tree[i] = -1;
		mincost[i] = 1e9;
		cin >> cost[i];
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	for (int i = 1; i <= N; i++) mincost[find(i)] = min(mincost[find(i)], cost[i]);
	for (int i = 1; i <= N; i++) res += mincost[i] % (int)1e9;
	if (k < res) cout << "Oh no\n";
	else cout << res << "\n";
}