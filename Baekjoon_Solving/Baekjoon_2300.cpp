#include <bits/stdc++.h>
using namespace std;
int N, DP[10001]; //DP[n] : n번째 건물부터 기지국을 설치해야 할때 남은 최소비용 
vector<pair<int, int>> vec;

int Solve(int n) {
	if (n == N) return 0;
	if (DP[n] != -1) return DP[n];
	int maxY = -2e9, ret = 2e9;
	for (int i = n; i < N; i++) {
		maxY = max(maxY, 2 * abs(vec[i].second));
		int cost = max(maxY, vec[i].first - vec[n].first);
		ret = min(ret, cost + Solve(i + 1));
	}
	return DP[n] = ret;
}

int main() {
	memset(DP, -1, sizeof(DP));
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		vec.push_back({ x,y });
	}
	sort(vec.begin(), vec.end());
	cout << Solve(0) << "\n";
}