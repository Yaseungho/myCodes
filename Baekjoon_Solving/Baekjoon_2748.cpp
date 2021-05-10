#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll N, DP[91];

int main() {
	cin >> N;
	DP[1] = 1;
	for (int i = 2; i <= N; i++) DP[i] = DP[i - 1] + DP[i - 2];
	cout << DP[N] << "\n";
}