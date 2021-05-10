#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll Dx[4] = { 0,1,0,-1 };
const ll Dy[4] = { 1,0,-1,0 };
queue<pair<ll, ll>> q;
ll N, K;
bool vit[2001][2001];
pll tree[2001][2001];

pll find(pll n) {
	if (tree[n.y][n.x].x < 0) return n;
	tree[n.y][n.x] = find(tree[n.y][n.x]);
	return tree[n.y][n.x];
}

void merge(pll a, pll b) {
	a = find(a);
	b = find(b);
	if (a.x == b.x && a.y == b.y) return;
	tree[a.y][a.x].x += tree[b.y][b.x].x;
	tree[b.y][b.x] = a;
}

void mergeadj(int a, int b) {
	for (int i = 0; i < 4; i++) {
		int nx = a + Dx[i], ny = b + Dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < N && vit[ny][nx]) merge({ a,b }, { nx,ny });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	ll res = 0, cnt = 0, a = 0, b = 0;
	for (int i = 0; i < 2001; i++) for (int j = 0; j < 2001; j++) tree[i][j] = { -1,-1 };
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		q.push({ a - 1, b - 1 });
		vit[b - 1][a - 1] = 1;
		cnt--;
		mergeadj(a - 1, b - 1);
	}
	pll cv = { a - 1, b - 1 };
	while (!q.empty()) {
		if (tree[find(cv).y][find(cv).x].x == cnt) {
			cout << res << "\n";
			return 0;
		}
		res++;
		ll sz = q.size();
		for (int i = 0; i < sz; i++) {
			pll now = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				ll nx = now.x + Dx[j], ny = now.y + Dy[j];
				if (0 <= nx && nx < N && 0 <= ny && ny < N && !vit[ny][nx]) {
					cnt--;
					q.push({ nx,ny });
					vit[ny][nx] = 1;
					mergeadj(nx, ny);
				}
			}
		}
	}
	cout << res << "\n";
}