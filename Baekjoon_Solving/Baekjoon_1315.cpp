#include <bits/stdc++.h>
using namespace std;
int N, STR[101], INT[101], PNT[101], DP[1001][1001], res = 0;

void solve(int S, int I) {
	if (DP[S][I] != -1) return;
	int cnt = 0, pnt = 0;
	for (int i = 0; i < N; i++) {
		if (S >= STR[i] || I >= INT[i]) {
			cnt++;
			pnt += PNT[i];
		}
	}
	DP[S][I] = cnt;
	pnt -= (S + I - 2);
	if (pnt > 0) for (int i = 0; i <= pnt; i++) solve(min(1000, S + i), min(1000, I + pnt - i));
}

int main() {
	memset(DP, -1, sizeof(DP));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> STR[i] >> INT[i] >> PNT[i];
	solve(1, 1);
	for (int i = 0; i < 1001; i++) for (int j = 0; j < 1001; j++) res = max(res, DP[i][j]);
	cout << res << "\n";
}