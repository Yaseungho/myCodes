#include <bits/stdc++.h>
using namespace std;
vector<int> dp[101][101];

vector<int> plu(vector<int> a, vector<int> b) {
	int sz = max(a.size(), b.size());
	a.resize(sz, 0);
	b.resize(sz, 0);
	vector<int> ret(sz);
	bool flag = false;
	for (int i = 0; i < sz; i++) {
		if (flag) {
			ret[i] = (a[i] + b[i] + 1) % 10;
			if (a[i] + b[i] + 1 >= 10) flag = true;
			else flag = false;
		}
		else {
			ret[i] = (a[i] + b[i]) % 10;
			if (a[i] + b[i] >= 10) flag = true;
		}
	}
	if (flag) ret.push_back(1);
	return ret;
}

vector<int> func(int n, int k) {
	if (n < k || k < 0) return vector<int>{ 0 };
	if (dp[n][k] != vector<int>{ 0 }) return dp[n][k];
	vector<int> ret = plu(func(n - 1, k - 1), func(n - 1, k));
	dp[n][k] = ret;
	return ret;
}

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < 101; i++) 
		for (int j = 0; j < 101; j++)
			dp[i][j] = vector<int>{ 0 };
	
	dp[0][0] = dp[1][0] = dp[1][1] = dp[2][2] = vector<int>{ 1 };
	dp[2][1] = vector<int>{ 2 };
	vector<int> res = func(N, K);
	reverse(res.begin(), res.end());
	for (int i : res) cout << i;
	cout << "\n";


	return 0;
}