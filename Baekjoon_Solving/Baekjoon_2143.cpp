#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> m;
ll nPsum[1001], mPsum[1001];
ll Nsum(ll s, ll e) {
	if (s == 0) return nPsum[e];
	return nPsum[e] - nPsum[s - 1];
}
ll Msum(ll s, ll e) {
	if (s == 0) return mPsum[e];
	return mPsum[e] - mPsum[s - 1];
}

int main() {
	ll T, N, M, mCnt = 0, nCnt = 0, res = 0;
	cin >> T >> N;
	for (ll i = 0; i < N; i++) {
		ll temp;
		cin >> temp;
		nCnt += temp;
		nPsum[i] = nCnt;
	}
	cin >> M;
	for (ll i = 0; i < M; i++) {
		ll temp;
		cin >> temp;
		mCnt += temp;
		mPsum[i] = mCnt;
	}
	for (ll i = 0; i < M; i++) {
		for (ll j = i; j < M; j++) {
			if (m.find(Msum(i, j)) == m.end()) m[Msum(i, j)] = 1;
			else m[Msum(i, j)]++;
		}
	}
	for (ll i = 0; i < N; i++) {
		for (ll j = i; j < N; j++) {
			ll toMake = T - Nsum(i, j);
			if (m.find(toMake) != m.end()) res += m[toMake];
		}
	}
	cout << res << "\n";
}