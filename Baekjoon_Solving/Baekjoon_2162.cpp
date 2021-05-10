#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;

struct line {
	ll x1, y1, x2, y2;
};
ll N, tree[3001];
bool roots[3001];
line arr[3001];

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

ll CCW(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll ret = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (ret < 0) return -1;
	else if (ret > 0) return 1;
	else return 0;
}

bool isinGroup(line a, line b) {
	ll res1 = CCW(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1) * CCW(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2);
	ll res2 = CCW(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1) * CCW(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2);
	if (res1 <= 0 && res2 <= 0) {
		if (!res1 && !res2) 
			return (max(a.x1, a.x2) >= min(b.x1, b.x2) && max(a.y1, a.y2) >= min(b.y1, b.y2) &&
					max(b.x1, b.x2) >= min(a.x1, a.x2) && max(b.y1, b.y2) >= min(a.y1, a.y2));
		else return true;
	}
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	memset(tree, -1, sizeof(tree));
	ll cnt = 0, sz = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].x1 >> arr[i].y1 >> arr[i].x2 >> arr[i].y2;
	for (int i = 0; i < N; i++) 
		for (int j = i + 1; j < N; j++) 
			if (isinGroup(arr[i], arr[j])) merge(i, j);
	for (int i = 0; i < N; i++) {
		if (find(i) >= 0 && !roots[find(i)]) {
			cnt++;
			roots[find(i)] = true;
		}
		sz = max(sz, -tree[find(i)]);
	}
	cout << cnt << "\n" << sz << "\n";
}