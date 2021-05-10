#include <bits/stdc++.h>
using namespace std;
int DP[2001][2001];
vector<int> vec;
int N;

int Solve(int s, int e) {
	if (DP[s][e] > 0) return DP[s][e];
	int next = 2 * vec[e] - vec[s];
	auto finded = lower_bound(vec.begin(), vec.end(), next);
	if (finded != vec.end() && *finded == next) {
		return DP[s][e] = 1 + Solve(e, finded - vec.begin());
	}
	return DP[s][e] = 2;
}

int main() {
	int res = 1;
	cin >> N;
	vec.resize(N);
	for (int i = 0; i < N; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if(vec[i] != vec[j]) res = max(res, Solve(i, j));
		}
	}
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (vec[i - 1] == vec[i]) {
			cnt++;
			res = max(res, cnt);
		}
		else cnt = 1;
	}
	cout << res << "\n";
}
