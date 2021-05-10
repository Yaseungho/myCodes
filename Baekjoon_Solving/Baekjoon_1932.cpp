#include <bits/stdc++.h>
using namespace std;
int arr[501][501], DP[501][501], N;

int func(int n, int m) {
	if (n == N) return 0;
	if (DP[n][m] != -1) return DP[n][m];
	return DP[n][m] = arr[n][m] + max(func(n + 1, m), func(n + 1, m + 1));
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
			DP[i][j] = -1;
		}
	}
	cout << func(0, 0);
}