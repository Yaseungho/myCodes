#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> res, vec;
ll DP[1000001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	ll N, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
		if (res.empty() || res[res.size() - 1] < num) {
			res.push_back(num);
			DP[i] = res.size() - 1;
		}
		else {
			auto it = lower_bound(res.begin(), res.end(), num);
			*it = num;
			DP[i] = it - res.begin();
		}
	}
	ll cnt = res.size() - 1, ind = N - 1;
	res.clear();
	while (cnt >= 0) {
		if (DP[ind] == cnt) {
			res.push_back(vec[ind]);
			cnt--;
		}
		ind--;
	}
	reverse(res.begin(), res.end());
	cout << res.size() << "\n";
	for (ll n : res) cout << n << " ";
}