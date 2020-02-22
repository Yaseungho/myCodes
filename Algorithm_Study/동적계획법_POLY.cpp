#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
#define MOD 10000000
int DP[101][101];

int func(int num, int back) {
	if (num == 0) return 1;
	if (DP[num][back] != -1) return DP[num][back];
	int ret = 0;
	for (int i = 1; i <= num; i++) {
		if (back == 0) ret += func(num - i, i) % MOD;
		else ret += ((back + i - 1) % MOD * func(num - i, i) % MOD) % MOD;

		ret %= MOD;
	}
	return DP[num][back] = ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int temp;
		memset(DP, -1, sizeof(DP));
		cin >> temp;
		cout << func(temp, 0) << "\n";
	}
}