#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll sumX = 0, sumY = 0, N;
pll p[20];

ll pick(ll cnt, ll prev, pll now) {
	if (cnt == N / 2) return pow(sumX - now.x * 2, 2) + pow(sumY - now.y * 2, 2);
	ll ret = 1e15;
	for (int i = prev + 1; i < N; i++) 
		ret = min(ret, pick(cnt + 1, i, { now.x + p[i].x, now.y + p[i].y }));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.precision(15);
	int T;
	cin >> T;
	while (T--) {
		sumX = sumY = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> p[i].x >> p[i].y;
			sumX += p[i].x;
			sumY += p[i].y;
		}
		cout << sqrt((double)pick(0, -1, { 0,0 })) << "\n";
	}
}