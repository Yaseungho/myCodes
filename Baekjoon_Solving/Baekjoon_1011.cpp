#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int s, e;
		cin >> s >> e;
		cout << ceil(2 * sqrt(e - s) - 1) << "\n";
	}
}