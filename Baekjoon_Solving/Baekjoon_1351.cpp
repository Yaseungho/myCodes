#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> DP;
ll N, P, Q;

ll solve(ll N) {
	if (N == 0) return 1;
	if (DP.find(N) != DP.end()) return DP[N];
	return DP[N] = solve(N / P) + solve(N / Q);
}

int main() {
	cin >> N >> P >> Q;
	cout << solve(N) << "\n";
}