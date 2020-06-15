#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
int DP[250][250];//DP[N][M] : N ~ M범위에서 만들수있는 수의 최댓값

int solve(int ind1, int ind2) {
	if (ind1 == ind2) return vec[ind1];
	if (ind2 - ind1 == 1 && vec[ind1] == vec[ind2]) return vec[ind1] + 1;

	if (DP[ind1][ind2] != -1) return DP[ind1][ind2];
	int ret = 0;
	for (int mid = ind1; mid < ind2; mid++) {
		if (solve(ind1,mid) == solve(mid + 1, ind2)) {
			ret = max(ret, solve(ind1, mid) + 1);
		}
	}
	return DP[ind1][ind2] = ret;
}

int main() {
	memset(DP, -1, sizeof(DP));
	int N, result = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			result = max(result, solve(i, j));
		}
	}
	cout << result << "\n";
}