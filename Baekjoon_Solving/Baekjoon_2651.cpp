#include <bits/stdc++.h>
using namespace std;
int k ,n;
vector<int> vec;
vector<int> cost;
int DP[103];//DP[n] : 현재 n번 위치에 있을때 도착지까지 최소 비용
int choices[103];

int Solve(int now) {
	if (DP[now] != -1) return DP[now];
	int ret = 1e9;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[now] < vec[i] && vec[i] <= vec[now] + k) {
			if (i == vec.size() - 1) {
				choices[now] = vec.size() - 1;
				return DP[now] = 0;
			}
			int val = cost[i - 1] + Solve(i);
			if (ret > val) {
				ret = val;
				choices[now] = i;
			}
		}
	}
	return DP[now] = ret;
}

void Print() {
	vector<int> res;
	int now = choices[0];
	while (now != vec.size() - 1) {
		res.push_back(now);
		now = choices[now];
	}
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
	cout << "\n";
}

int main() {
	memset(DP, -1, sizeof(DP));
	int cnt = 0;
	cin >> k >> n;
	cost.resize(n);
	vec.push_back(0);
	for (int i = 0; i < n + 1; i++) {
		int temp;
		cin >> temp;
		cnt += temp;
		vec.push_back(cnt);
	}
	for (int i = 0; i < n; i++) cin >> cost[i];
	int res = Solve(0);
	cout << res << "\n";
	Print();
}