#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll N;

ll func(ll key) {
	ll ret = 0;
	for (ll i = 1; i <= N; i++) ret += min(N, key / i);
	return ret;
}

int main() {
	ll K, s = 0, e = 1e9;
	cin >> N >> K;
	while (s <= e) {
		ll mid = (s + e) / 2;
		if (func(mid) < K) s = mid + 1;
		else e = mid - 1;
	}
	cout << s << "\n";
}