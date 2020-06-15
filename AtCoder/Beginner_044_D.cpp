#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long func(long long b, long long n) {
	if (b < 2) return -1;
	if (b > n) return n;
	else return func(b, n / b) + (n % b);
}
 
int main() {
	long long n, s;
	cin >> n >> s;
	if (n == s) {
		cout << n + 1 << "\n";
	}
	else {
		bool is = true;
		for (long long i = 2; i * i <= n; i++) {
			if (func(i, n) == s) {
				cout << i << "\n";
				is = false;
				break;
			}
		}
		if (is) {
			long long result = -1;
			for (long long i = 1; i * i <= n; i++) {
				long long key = (n - s) / i + 1;
				if (func(key, n) == s) result = key;
			}
			cout << result << "\n";
		}
	}
	return 0;
}