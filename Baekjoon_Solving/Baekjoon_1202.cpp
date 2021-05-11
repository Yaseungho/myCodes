#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
priority_queue <pll> jewels;
multiset<ll> bags;
ll N, K;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	ll res = 0;																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																			
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		ll m, v;
		cin >> m >> v;
		jewels.push({ v,m });
	}
	for (int i = 0; i < K; i++) {
		int n;
		cin >> n;
		bags.insert(n);
	}
	while (1) {
		if (jewels.empty() || bags.empty()) break;
		pll now = jewels.top(); jewels.pop();
		auto it = bags.lower_bound(now.second);
		if (it != bags.end()) {
			res += now.first;
			bags.erase(it);
		}
	}
	cout << res << "\n";
}