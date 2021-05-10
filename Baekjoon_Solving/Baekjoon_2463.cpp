#include <bits/stdc++.h>
#define x first
#define y second
#define MOD (int)1e9
using namespace std;
typedef long long ll;
ll N, M, tree[100001];
vector<pair<ll, pair<ll, ll>>> edges;
set<ll> components;


ll pairsum(ll n) {
	return n * (n - 1) / 2;
}

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
	ll res = 0, cnt = 0;
	memset(tree, -1, sizeof(tree));
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		ll a, b, w;
		cin >> a >> b >> w;
		edges.push_back({ w,{a,b} });
	}
	sort(edges.begin(), edges.end());
	reverse(edges.begin(), edges.end());
	
	for (auto i : edges) {
		cnt -= pairsum(-tree[find(i.y.x)]) + pairsum(-tree[find(i.y.y)]);
		if (find(i.y.x) == find(i.y.y)) cnt += pairsum(-tree[find(i.y.x)]);
		ll cost = i.x;
		merge(i.y.x, i.y.y);
		cnt += pairsum(-tree[find(i.y.x)]);
		res = (res % MOD + (cnt * i.x) % MOD) % MOD;
	}
	cout << res << "\n";
}