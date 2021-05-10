#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

vector<ll> vec;

ll func(ll x) {
	ll ret = 1, cnt = 0;
	for (ll i = 0; i < vec.size(); i++) {
		if (cnt + vec[i] > x) {
			cnt = vec[i];
			ret++;
		}
		else cnt += vec[i];
	}
	return ret;
}

int main() {
	ll N, M, s = 0, e = 2e9;
	cin >> N >> M;
	while (N--) {
		ll temp;
		cin >> temp;
		vec.push_back(temp);
		s = max(s, temp);
	}
	while (s <= e) {
		ll mid = (s + e) / 2;
		if (func(mid) > M) s = mid + 1;
		else e = mid - 1;
	}
	cout << e + 1 << "\n";
}