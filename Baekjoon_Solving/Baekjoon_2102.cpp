#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll psum[100001], N, M;

bool judge(ll x) {
	ll minS = 0, nowE;
	for (ll i = 1; i <= N - M + 1; i++) {
		minS = min(minS, psum[i - 1] * 1000 - x * (i - 1));
		nowE = psum[i + M - 1] * 1000 - x * (i + M - 1);
		if (nowE >= minS) return 1;
	}
	return 0;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		ll temp;
		cin >> temp;
		psum[i + 1] = psum[i] + temp;
	}
	ll s = 0, e = 2000000;
	while (s <= e) {
		ll mid = (s + e) / 2;
		if (judge(mid)) s = mid + 1;
		else e = mid - 1;
	}
	cout << e << "\n";
}
