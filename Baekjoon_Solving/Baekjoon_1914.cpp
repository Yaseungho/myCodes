#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

vector<pair<int, int>> vec;

string bignum(string num1, string num2) {
	int sum = 0;
	string result;
	while (sum | !num1.empty() | !num2.empty()) {
		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

string subtractOne(string num) {
	int back = num.back() - '0';
	num.pop_back();
	back -= 1;
	num.push_back(back + '0');
	return num;
}

void Hanoi(int n, int from, int to, int middle) {
	if (n == 0) return;
	Hanoi(n - 1, from, middle, to);
	vec.push_back({ from, to });
	Hanoi(n - 1, middle, to, from);
}

int main() {
	int n;
	scanf_s("%d", &n);

	if (n <= 20) {
		Hanoi(n, 1, 3, 2);
		cout << vec.size() << "\n";
		for (int i = 0; i < vec.size(); i++) printf("%d %d\n", vec[i].first, vec[i].second);
	}
	else {
		string num = "2";

		for (int i = 0; i < n - 1; i++) {
			string temp = bignum(num, num);
			num = temp;
		}
		cout << subtractOne(num) << "\n";
	}
	return 0;
}