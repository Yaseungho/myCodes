#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
long long DP[101][1001];//dp[n][m] : n번째 숫자를 고려해야 하고 현 상태가 m일 때 부호를 계속 붙여서 원하는 결과가 나오는 경우의수
vector<int> vec;
int n, num;

long long solve(int ind, int now) {
	if (ind == n - 1) {
		if (now == num) return 1;
		else return 0;
	}
	if (DP[ind][now] != -1) return DP[ind][now];
	long long ret = 0;
	if (now - vec[ind] >= 0) ret += solve(ind + 1, now - vec[ind]);
	if (now + vec[ind] <= 20) ret += solve(ind + 1, now + vec[ind]);
	return DP[ind][now] = ret;
}

int main() {
	memset(DP, -1, sizeof(DP));
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	cin >> num;
	cout << solve(1, vec[0]) << "\n";
}