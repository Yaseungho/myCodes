#include <iostream>
#include <vector>
#define MOD 15746
using namespace std;
vector<int> dp;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i <= N; i++) {
		dp.push_back(-1);
	}
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) dp[i] = (dp[i - 1] % MOD + dp[i - 2] % MOD) % MOD;
	
	cout << dp[N];
	return 0;
}