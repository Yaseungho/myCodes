#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> vec;

int main() {
	ll N, M, time, s = 0, e = INT_MAX, result = -1;
	cin >> N >> M;
	vec.resize(N);
	for (int i = 0; i < N; i++) cin >> vec[i];
	while (s <= e) {
		ll mid = (s + e) / 2, cnt = 0;
		for (int i = 0; i < N; i++) cnt += max(0ll, vec[i] - mid);
		if (cnt < M) e = mid - 1;
		else s = mid + 1;
	}
	cout << e << "\n";
}