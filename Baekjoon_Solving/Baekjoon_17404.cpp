#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, arr[1001][3], DP[1001][3], s;

ll solve(ll now, ll prev) {
	if (now == N) return 0;
	ll next = -1;
	if (now == N - 1) next = s;

	if (DP[now][prev] != -1) return DP[now][prev];
	ll ret = 2e9;
	for (int i = 0; i < 3; i++) {
		if (i == prev || i == next) continue;
		ret = min(ret, arr[now][i] + solve(now + 1, i));
	}
	return DP[now][prev] = ret;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	ll res = 2e9;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	for (int i = 0; i < 3; i++) {
		memset(DP, -1, sizeof(DP));
		s = i;
		res = min(res, arr[0][i] + solve(1, i));
	}
	cout << res << "\n";
}