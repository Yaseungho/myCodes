#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(const string str1, const string str2) {
	unsigned long long sum, temp1 = 0, temp2 = 0, n1 = 1, n2 = 1;
	for (int i = str1.size() - 1; i >= 0; i--) {
		temp1 += ((unsigned long long)str1[i] - 48) * n1;
		n1 *= 10;
	}
	for (int i = str2.size() - 1; i >= 0; i--) {
		temp2 += ((unsigned long long)str2[i] - 48) * n2;
		n2 *= 10;
	}
	return (temp1 * n2) + temp2 > (temp2 * n1) + temp1;
}

bool compare2(const string max, const string str) {
	int temp1 = 0, temp2 = 0, n = 1;
	for (int i = max.size() - 1; i >= 0; i--) {
		temp1 += (max[i] - 48) * n;
		n *= 10;
	} n = 1;
	for (int i = str.size() - 1; i >= 0; i--) {
		temp2 += (str[i] - 48) * n;
		n *= 10;
	}
	return temp1 < temp2;
}

int main() {
	vector<string> vec;
	int K, N;
	string max = "0";
	cin >> K >> N;
	int k = K;
	while (K--) {
		string num;
		cin >> num;
		if (compare2(max, num)) max = num;
		vec.push_back(num);
	}
	for (int i = 0; i < (N - k); i++) vec.push_back(max);
	sort(vec.begin(), vec.end(), compare);
	for (auto& v : vec) cout << v;
	return 0;
}