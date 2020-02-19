#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int DP[10001][2];
vector<int> vec;

int func(int num, int cnt) {
	if (num > N) return 0;
	if (DP[num][cnt] != -1) return DP[num][cnt];
	int ret;
	if (cnt == 1) ret = max(func(num + 2, 0) + vec[num], func(num + 3, 0) + vec[num]);
	else ret = max(func(num + 1, cnt + 1) + vec[num], func(num + 2, 0) + vec[num]);
	return DP[num][cnt] = ret;
}

int main() {
	int val;
	cin >> N;
	vec.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> val;
		vec.push_back(val);
	}
	for (int i = 0; i < 10001; i++) {
		DP[i][0] = -1;
		DP[i][1] = -1;
	}
	cout << max(func(1, 0), func(2, 0));
	return 0;
}