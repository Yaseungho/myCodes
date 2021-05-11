#include <bits/stdc++.h>
using namespace std;
int N, M, arr[2002], DP[2002][2002];
//DP[s][e] : 구간 s,e가 팰린드롬인가?

bool solve(int s, int e) {
	if (e - s <= 1) return arr[e] == arr[s];
	if (DP[s][e] != -1) return DP[s][e];
	return DP[s][e] = arr[e] == arr[s] && solve(s + 1, e - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	memset(DP, -1, sizeof(DP));
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	cin >> M;
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		cout << solve(s, e) << "\n";
	}
}