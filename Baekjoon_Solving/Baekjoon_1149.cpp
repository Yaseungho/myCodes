#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int DP[1001][3];//지금 집의 인덱스, 이전 집의 색깔 
vector< vector<int> > vec;
int N;

int func(int ind, int color) {
	if (ind == N) return 0;
	if (color != -1) {
		if (DP[ind][color] != -1) return DP[ind][color];
	}
	int ret = 99999999;
	for (int i = 0; i < 3; i++) {
		if (i == color) continue;
		ret = min(ret, vec[ind][i] + func(ind + 1, i));
	}
	return DP[ind][color] = ret;
}

int main() {
	memset(DP, -1, sizeof(DP));
	int temp1, temp2, temp3;
	cin >> N;
	vec.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2 >> temp3;
		vec[i].push_back(temp1);
		vec[i].push_back(temp2);
		vec[i].push_back(temp3);
	}
	cout << func(0, -1);
	return 0;
}