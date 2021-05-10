#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll DP[1000001], choice[1000001];
vector<ll> res;

ll solve(ll N) {
	if (N == 1) return 0;
	if (DP[N] != -1) return DP[N];
	ll ret = 2e9;
	if (ret > solve(N - 1)) {
		choice[N] = N - 1;
		ret = solve(N - 1);
	}
	if (!(N % 2)) {
		if (ret > solve(N / 2)) {
			choice[N] = N / 2;
			ret = solve(N / 2);
		}
	}	
	if (!(N % 3)) {
		if (ret > solve(N / 3)) {
			choice[N] = N / 3;
			ret = solve(N / 3);
		}
	}
	return DP[N] = 1 + ret;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	memset(DP, -1, sizeof(DP));
	ll N; 
	cin >> N;
	cout << solve(N) << "\n";
	while (N != 1) {
		res.push_back(N);
		N = choice[N];
	}
	res.push_back(1);
	for (ll n : res) cout << n << " ";
}