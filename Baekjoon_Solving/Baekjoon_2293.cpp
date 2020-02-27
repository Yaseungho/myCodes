#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DP[10001] = { 0 };

int main() {
	vector<int> coins;
	int n, k, temp;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		coins.push_back(temp);
	}
	sort(coins.begin(), coins.end());
	DP[k] = 1;
	for (int i = 0; i < n; i++) 
		for (int j = k; j >= 0; j--) 
			if (j - coins[i] >= 0) 
				DP[j - coins[i]] += DP[j];
	cout << DP[0] << "\n";
}