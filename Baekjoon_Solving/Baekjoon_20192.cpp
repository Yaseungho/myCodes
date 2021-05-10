#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, cur = 0, res = 1, val;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> val;
		if (res % 2) {
			if (cur > val) res++;
		}
		else if (cur < val) res++;
		cur = val;
	}
	cout << ceil(log2(res));
}