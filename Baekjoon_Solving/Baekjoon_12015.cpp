#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> res, vec;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	ll N, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
		if (res.empty() || res[res.size() - 1] < num) res.push_back(num);
		else {
			auto it = lower_bound(res.begin(), res.end(), num);
			*it = num;
		}
	}
	cout << res.size() << "\n";
}