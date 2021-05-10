#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void check(int& m, int& val) {
	if (m > val) {

	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	ll N, m = 1e15;
	cin >> N;
	vector<ll> vec(N), res(3);
	for (int i = 0; i < N; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 2; j < N; j++) {
			ll val = vec[i] + vec[j];
			auto it = upper_bound(vec.begin() + i + 1, vec.begin() + j, -val);
			if (it != vec.begin() + j) {
				if (m > abs(val + (*it))) {
					res = { vec[i], vec[j], (*it) };
					m = abs(val + (*it));
				}
			}
			if (it != vec.begin() + i + 1) it--;
			if (m > abs(val + (*it))) {
				res = { vec[i], vec[j], (*it) };
				m = abs(val + (*it));
			}
		}
	}
	sort(res.begin(), res.end());
	cout << res[0] << " " << res[1] << " " << res[2] << "\n";
}