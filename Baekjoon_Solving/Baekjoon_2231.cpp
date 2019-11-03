#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int func(int num) {
	int ret = 0;
	while (num > 0) {
		ret += num % 10;
		num /= 10;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	int n;
	bool is = true;
	cin >> n;
	for (int i = 0; i < n; i++) {
		if (i + func(i) == n) {
			cout << i;
			is = false;
			break;
		}
	}
	if (is) cout << 0;
}