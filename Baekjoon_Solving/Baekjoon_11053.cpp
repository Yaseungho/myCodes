#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int A;
int dp[1001];
vector<int> vec;

int func(int num) {
	if (dp[num] != -1) return dp[num];
	int ret = 0;
	for (int i = num + 1; i < A; i++) {
		if (vec[num] < vec[i]) {
			ret = max(ret, (func(i) + 1));
		}
	}
	dp[num] = ret;
	return ret;
}

int main() {
	int temp;
	int result = 0;
	cin >> A;
	for (int i = 0; i < 1001; i++) {
		dp[i] = -1;
	}
	for (int i = 0; i < A; i++) {
		cin >> temp;
		vec.push_back(temp);
	}
	for (int i = 0; i < A; i++) {
		result = max(func(i), result);
	}
	cout << result + 1 << "\n";
}