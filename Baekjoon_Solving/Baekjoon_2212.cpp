#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> vec;
	vector<int> Darr;
	int N, K, sum = 0;
	cin >> N >> K;
	while (N--) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < (int)vec.size() - 1; i++) Darr.push_back(vec[i + 1] - vec[i]);
	if (!Darr.empty()) {
		sort(Darr.begin(), Darr.end(), greater<int>());
		for (int i = 0; i < K - 1; i++) Darr[i] = 0;
		for (auto& v : Darr) sum += v;
		cout << sum;
	}
	else cout << "0";
	return 0;
}