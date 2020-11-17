#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, sum = 0, mn = 99999;
	cin >> N >> M;
	for (int i = 1; i <= 100; i++) {
		int pw = i * i;
		if (N <= pw && pw <= M) {
			sum += pw;
			mn = min(mn, pw);
		}
	}
	if (mn == 99999) cout << "-1\n";
	else cout << sum << "\n" << mn << "\n";
}