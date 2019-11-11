#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int,int>& temp1, const pair<int, int>& temp2) {
	if (temp1.second == temp2.second) return temp1.first < temp2.first;
 	return temp1.second > temp2.second;
}

int main() {
	vector<pair<int, int>> vec;//first는 마감일, second는 점수
	int arr[1001] = { 0 };
	int N, sum = 0;
	cin >> N;
	while (N--) {
		int num1, num2;
		cin >> num1 >> num2;
		vec.push_back(make_pair(num1, num2));
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < (int)vec.size(); i++) {
		for (int j = vec[i].first - 1; j >= 0; j--) {
			if (!arr[j]) {
				arr[j] = vec[i].second;
				sum += vec[i].second;
				break;
			}
		}
	}
	cout << sum;
	return 0;
}