#include <iostream>
#include <queue>
#define MOD 20090711
using namespace std;
int a, b;

struct RandNumGenerator {
	int value = 1983;
	int next() {
		int ret = value;
		value = (value * (long long)a + b) % MOD;
		return ret;
	}
};

int main() {
	int c;
	cin >> c;
	while (c--) {
		int result = 0;
		int n;
		cin >> n >> a >> b;
		RandNumGenerator RNG;
		priority_queue<int, vector<int>, less<int>> max;
		priority_queue<int, vector<int>, greater<int>> min;
		for (int i = 0; i < n; i++) {
			int val = RNG.next();
			if (max.size() == min.size()) max.push(val);
			else min.push(val);
			if (!max.empty() && !min.empty() && max.top() > min.top()) {
				int temp1 = max.top(), temp2 = min.top();
				min.pop(); max.pop();
				min.push(temp1); max.push(temp2);
			}
			result += max.top();
			result %= MOD;
		}
		cout << result << "\n";
	}
}