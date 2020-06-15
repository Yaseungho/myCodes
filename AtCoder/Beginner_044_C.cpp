#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N, A;
long long DP[51][51][2501]; 
//DP[i][j][k] : i번째 카드 전까진 고려했으며 j개의 카드를 골랐고 고른 카드의 합이 k일때 남은 카드를 골라 A를 만드는 경우의수
vector<int> vec;

long long solve(int ind,int picked, int sum) {
	if (ind == N) {
		if (picked == 0) return 0;
		else if (sum == A * picked) return 1;
		else return 0;
	}
	if (DP[ind][picked][sum] != -1) return DP[ind][picked][sum];
	long long ret = 0;
	ret += solve(ind + 1, picked, sum);
	ret += solve(ind + 1, picked + 1, sum + vec[ind]);
	return DP[ind][picked][sum] = ret;
}

int main() {
	memset(DP, -1, sizeof(DP));
	cin >> N >> A;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	cout << solve(0, 0, 0) << "\n";
}