#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int adj[201][201], tree[201], N, M;

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

bool judge() {
	vector<int> arr;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	int a = arr[0];
	for (int i = 0; i < M; i++) if (find(a - 1) != find(arr[i] - 1)) return false;
	return true;
}

int main() {
	for (int i = 0; i < 201; i++) tree[i] = -1;
	cin >> N >> M;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> adj[i][j];
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			if (adj[i][j]) merge(i, j);
	cout << (judge() ? "YES\n" : "NO\n") << "\n";
}