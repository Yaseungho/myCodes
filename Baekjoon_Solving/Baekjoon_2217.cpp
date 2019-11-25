#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, i, j;
	vector<int> vec;
	cin >> N;
	while (N--) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end(), greater<int>());
	int max = 0;
	for (i = 1; i <= (int)vec.size(); i++) {
		int temp = vec[i - 1] * i;
		if (temp > max) {
			max = temp;
			//cout << vec[i-1] << " * "<< i << "가 최대값이 됨\n";
		}
	}
	cout << max;
	return 0;
}