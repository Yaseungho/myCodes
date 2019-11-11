#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(const pair<int,int>& temp1, const pair<int, int>& temp2) {
	return temp1.second > temp2.second;
}

int main() {
	long long L, N, r, b, result = 0;
	bool Rest = false, is = true;
	vector<pair<long long, long long>> vec;//first는 위치, second는 만족도
	cin >> L >> N >> r >> b;
	while (N--) {
		long long num1, num2;
		cin >> num1 >> num2;
		vec.push_back(make_pair(num1, num2));
	}
	sort(vec.begin(), vec.end(), compare);

	long long start = 0;
	for (int i = 0; i < (int)vec.size(); i++) {
		if (start > vec[i].first) continue;
		long long restTime = (vec[i].first - start) * r - (vec[i].first - start) * b;
		result += restTime * vec[i].second;
		start = vec[i].first;
	}
	cout << result;
	return 0;
}