#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, n;
vector<ll> vec;
vector<ll> cost;
ll DP[103];//DP[n] : 현재 n번 위치에 있을때 도착지까지 최소 비용
ll choices[103];

ll Solve(ll now) {
	if (DP[now] != -1) return DP[now];
	ll ret = 3e9;
	for (ll i = 0; i < vec.size(); i++) {
		if (vec[now] < vec[i] && vec[i] <= vec[now] + k) {
			if (i == vec.size() - 1) {
				choices[now] = vec.size() - 1;
				return DP[now] = 0;
			}
			ll val = cost[i - 1] + Solve(i);
			if (ret > val) {
				ret = val;
				choices[now] = i;
			}
		}
	}
	return DP[now] = ret;
}

void Print() {
	vector<ll> res;
	ll now = choices[0];
	while (now != vec.size() - 1) {
		res.push_back(now);
		now = choices[now];
	}
	cout << res.size() << "\n";
	for (ll i = 0; i < res.size(); i++) cout << res[i] << " ";
	cout << "\n";
}

int main() {
	memset(DP, -1, sizeof(DP));
	ll cnt = 0;
	cin >> k >> n;
	cost.resize(n);
	vec.push_back(0);
	for (ll i = 0; i < n + 1; i++) {
		ll temp;
		cin >> temp;
		cnt += temp;
		vec.push_back(cnt);
	}
	for (ll i = 0; i < n; i++) cin >> cost[i];
	ll res = Solve(0);
	cout << res << "\n";
	Print();
}