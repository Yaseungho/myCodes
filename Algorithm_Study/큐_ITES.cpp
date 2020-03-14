#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Rand {
	unsigned value;
	Rand() : value(1983) {}
	unsigned next() {
		unsigned ret = value;
		value = (value * 214013u) + 2531011u;
		return ret % 10000 + 1;
	}
};

int func(int K, int N) {
	Rand Generator;
	queue<int> arr;
	int ret = 0, sum = 0;
	while (N--) {
		int val = Generator.next();
		sum += val;
		arr.push(val);
		while (sum > K) {
			sum -= arr.front();
			arr.pop();
		}
		if (sum == K) ret++;
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int K, N;
		cin >> K >> N;
		cout << func(K, N) << "\n";
	}
	return 0;
}