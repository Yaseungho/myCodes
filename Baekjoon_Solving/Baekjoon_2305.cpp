#include <bits/stdc++.h>
using namespace std;
int N, K, DP[41][2][2][2];
//DP[n][s1][s2][s3]
//n : 현재 앉아야 하는 사람의 번호 
//s1 : 뒷자리가 비어있는가(T/F)?
//s2 : 내자리가 비어있는가(T/F)?
//s2 : 자유석이 비어있는가(T/F)?

int Solve(int n, bool st1, bool st2, bool st3) {
	if (n == N) return (st2 ? 1 : 0);
	if (DP[n][st1][st2][st3] != -1) return DP[n][st1][st2][st3];
	if (n == K) return DP[n][st1][st2][st3] = Solve(n + 1, 0, 1, st3);
	int ret = 0;
	if (st3) ret += Solve(n + 1, st2, 1, 0);
	if (st2) ret += Solve(n + 1, 0, 1, st3);
	if (st1) ret += Solve(n + 1, st2, 1, st3);
	if (n + 1 != K) ret += Solve(n + 1, st2, 0, st3);
	return DP[n][st1][st2][st3] = ret;
}

int main() {
	memset(DP, -1, sizeof(DP));
	cin >> N >> K; K--;
	cout << Solve(0,0,1,1) << "\n";
}