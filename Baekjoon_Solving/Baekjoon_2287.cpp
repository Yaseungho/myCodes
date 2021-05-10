#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> DP[9];
int K, N;

set<int> solve(int N) {
	if (N == 0) return set<int>{};
	if (DP[N] != set<int>{}) return DP[N];
	set<int> ret;
	int num = 0, mul = 1;
	for (int i = 0; i < N; i++) {
		num += K * mul;
		mul *= 10;
	}
	ret.insert(num);
	for (int i = 1; i < N; i++) {
		set<int> A = solve(i);
		set<int> B = solve(N - i);
		for (auto i = A.begin(); i != A.end(); i++) {
			for (auto j = B.begin(); j != B.end(); j++) {
				ret.insert((*i) + (*j));
				ret.insert((*i) - (*j));
				ret.insert((*i) * (*j));
				if(*j != 0) ret.insert((*i) / (*j));
			}
		}
	}
	return DP[N] = ret;
}

int main() {
	for (int i = 0; i < 9; i++) DP[i] = set<int>{};
	cin >> K >> N;
	DP[1] = { K };
	solve(8);
	while (N--) {
		int num, res = -1; cin >> num;
		for (int i = 8; i >= 0; i--) {
			if (DP[i].find(num) != DP[i].end() ) res = i;
		}
		if (res == -1) cout << "NO\n";
		else cout << res << "\n";
	}
}