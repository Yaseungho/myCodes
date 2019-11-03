#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n = 10, num, sum = 0;
	vector<int> vec;
	vector<int> sex;
	while (n--) {
		cin >> num;
		vec.push_back(num);
	}
	for (int i = 0; i < 10; i++) {
		sum += vec[i];
		sex.push_back(sum);
		if (sum > 100) break;
	}
	cout << ( abs(100 - sex[sex.size() - 1]) > abs(100 - sex[sex.size() - 2]) ? sex[sex.size() - 2] : sex[sex.size() - 1]);
	return 0;
}