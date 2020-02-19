#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long goal;
int DP[101];

int Use(int num){
	if (num == goal) return 0;
	if (num > goal) return 9999999999;
	if (DP[num] != -1) return DP[num];
	return DP[num] = min(min(Use(num + 1) + 1, Use(num + 10) + 1), Use(num + 25) + 1);
}

int main() {
	int T, res = 0;
	long long cost;
	vector<int> results;
	cin >> T;
	while (T--) {
		res = 0;
		cin >> cost;
		while (cost) {
			for (int i = 0; i < 101; i++) DP[i] = -1;
			goal = cost % 100;
			res += Use(0);
			cost /= 100;
		}
		results.push_back(res);
	}
	for (auto& v : results) cout << v << "\n";
	return 0;
}