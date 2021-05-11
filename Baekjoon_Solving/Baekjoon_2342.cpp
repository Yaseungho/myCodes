#include <bits/stdc++.h>
using namespace std;
int cost[5][5]{
	{1,2,2,2,2},
	{0,1,3,4,3},
	{0,3,1,3,4},
	{0,4,3,1,3},
	{0,3,4,3,1}
}, DP[100001][5][5];
vector<int> vec;
/*
	1
2	0	4
	3
*/

int solve(int now, int a, int b) {
	if (a == b && a != 0) return 2e9;
	if (now == vec.size()) return 0;
	if (DP[now][a][b] != -1) return DP[now][a][b];
	int next = vec[now];
	return DP[now][a][b] =
		min(cost[a][next] + solve(now + 1, next, b),
			cost[b][next] + solve(now + 1, a, next));
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	memset(DP, -1, sizeof(DP));
	for (int i = 0;; i++) {
		int n;
		cin >> n;
		if (n == 0) break;
		vec.push_back(n);
	}
	cout << solve(0, 0, 0) << "\n";
}