#include <bits/stdc++.h>
using namespace std;
int k[3], DP[501][501];//n,m일때 선공이 이길 수 있는가 (t/f)?

bool solve(int n, int m) {
	if (n < 0 || m < 0) return 1;
	if (DP[n][m] != -1) return DP[n][m];
	bool ret = true;
	for (int i = 0; i < 3; i++) {
		ret *= solve(n - k[i], m);
		ret *= solve(n, m - k[i]);
	}
	return DP[n][m] = !ret;
}

int main() {
	memset(DP, -1, sizeof(DP));
	cin >> k[0] >> k[1] >> k[2];
	DP[0][0] = 0;
	for (int i = 0; i < 5; i++) {
		int n, m;
		cin >> n >> m;
		cout << (solve(n, m) ? "A" : "B") << "\n";
	}
}