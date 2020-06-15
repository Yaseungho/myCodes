#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;
long long dp[501][501]; // dp[ind1][ind2] = ind1 ~ ind2범위내의 행렬들의 연쇄 행렬곱의 최소 계산 횟수
vector<pair<long long, long long>> vec;

long long solve(int ind1, int ind2) {
	if (ind2 - ind1 == 1) return vec[ind1].first * vec[ind1].second * vec[ind2].second;
	if (ind1 == ind2) return 0;
	if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
	long long ret = 99999999999;
	for (int mid = ind1; mid < ind2; mid++) {
		ret = min(ret, solve(ind1, mid) + solve(mid + 1, ind2) + 
			(vec[ind1].first * vec[mid].second * vec[ind2].second));
	}
	return dp[ind1][ind2] = ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int  N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int r, c;
		cin >> r >> c;
		vec.push_back({ r,c });
	}
	cout << solve(0, N - 1) << "\n";
}