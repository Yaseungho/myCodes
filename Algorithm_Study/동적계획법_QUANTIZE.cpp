#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int DP[1001][11];
//DP[a][b] : a번째 인덱스부터 시작해 b개의 부분수열로 나누었을 때 오차 제곱의 최소

int error(int start, int end, const vector<int>& vec) {
	int sum = 0;
	for (int i = start; i <= end; i++) sum += vec[i];
	int pivot = (int)round((double)sum / ((double)end - (double)start + 1));
	sum = 0;
	for (int i = start; i <= end; i++) sum += (vec[i] - pivot) * (vec[i] - pivot);
	return sum;
}//error(3,5) : 3~5번째 인덱스에 대해 계산

int func(int ind, int num, const vector<int>& vec) {
	if (ind == vec.size()) return 0;
	if (!num) return 99999999;
	if (DP[ind][num] != -1) return DP[ind][num];
	int ret = 99999999;
	for (int i = ind; i < vec.size(); i++) {
		ret = min(ret, error(ind, i, vec) + func(i + 1, num - 1, vec));
	}
	return DP[ind][num] = ret;
}//ind 부터 시작해서 끊을 범위 고르기

int main() {
	int C;
	cin >> C;
	while (C--) {
		memset(DP, -1, sizeof(DP));
		int n, s, temp;
		vector<int> vec;
		cin >> n >> s;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			vec.push_back(temp);
			sort(vec.begin(), vec.end());
		}
		cout << func(0, s, vec) << "\n";
	}
}