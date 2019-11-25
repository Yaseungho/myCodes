#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main() {
	int N;
	cin >> N;
	fill(dp, dp + 1000001, 1000000000);
	dp[1] = 0;

	for (int i = 1; i < 1000001; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		if (i * 2 < 1000001) dp[i * 2] = min(dp[i * 2], dp[i] + 1);
		if (i * 3 < 1000001) dp[i * 3] = min(dp[i * 3], dp[i] + 1);
	}
	cout << dp[N];
	return 0;
}