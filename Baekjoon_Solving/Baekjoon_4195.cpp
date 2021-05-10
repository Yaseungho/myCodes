#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
ll N, tree[200001];
unordered_map<string, ll> ID;

ll find(ll n) {
	if (tree[n] < 0) return n;
	tree[n] = find(tree[n]);
	return tree[n];
}

void merge(ll a, ll b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	tree[a] += tree[b];
	tree[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	ll T;
	cin >> T;
	while (T--) {
		memset(tree, -1, sizeof(tree));
		ID.clear();
		cin >> N;
		ll temp = 0;
		for (int i = 0; i < N; i++) {
			string a, b;
			cin >> a >> b;
			if (ID.find(a) == ID.end()) ID[a] = temp++;
			if (ID.find(b) == ID.end()) ID[b] = temp++;
			merge(ID[a], ID[b]);
			cout << -tree[find(ID[a])] << "\n";
		}
	}
}