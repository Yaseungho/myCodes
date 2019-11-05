#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> vec;
	int N, K, cnt = 0;
	cin >> N >> K;
	while (N--) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		int temp = K / vec[i];
		K -= temp * vec[i];
		cnt += temp;
	}
	cout << cnt;
	return 0;
}