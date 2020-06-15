#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int N;
int dp[1001];
vector<int> vec;

int func(int num) {
	if (dp[num] != -1) return dp[num];
	int ret = 0;
	for (int i = num + 1; i < N; i++) if (vec[num] < vec[i]) ret = max(ret, (func(i) + 1));
	dp[num] = ret;
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int temp;
	int result = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		vec.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		result = max(func(i), result);
	}
	cout << N - result - 1 << "\n";
}