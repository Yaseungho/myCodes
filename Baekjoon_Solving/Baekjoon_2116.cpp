#include <bits/stdc++.h>
using namespace std;
int N;
struct dice {
	int down[6];
	int up[6];
	int val[6];
};
vector<dice> dices;

int Max(int a, int b, int c, int d) {
	return max(a, max(b, max(c, d)));
}

int Solve(int now, int prev) {
	if (now == N) return 0;
	for (int i = 0; i < 6; i++) {
		if (dices[now].down[i] == prev) {
			return dices[now].val[i] + Solve(now + 1, dices[now].up[i]);
		}
	}
}

int main() {
	int res = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B, C, D, E, F;
		cin >> A >> B >> C >> D >> E >> F;
		dices.push_back(dice{
			{A,B,C,D,E,F},
			{F,D,E,B,C,A}, 
			{Max(B,D,C,E),Max(A,F,C,E), Max(A,F,B,D), 
			Max(A,F,C,E),Max(A,F,B,D), Max(B,D,C,E)}
		});
	}
	for (int i = 0; i < 6; i++) res = max(res, dices[0].val[i] + Solve(1, dices[0].up[i]));
	cout << res << "\n";
}