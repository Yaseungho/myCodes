#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int DP[100001];
vector<int> vec;

int main() {
	int N, num, result = -999999;
	cin >> N;
	vec.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	DP[N] = vec[N];
	for (int i = N - 1; i > 0; i--) DP[i] = max(vec[i], vec[i] + DP[i + 1]);
	for (int i = 1; i <= N; i++) result = max(result, DP[i]);
	cout << result;
	return 0;
}