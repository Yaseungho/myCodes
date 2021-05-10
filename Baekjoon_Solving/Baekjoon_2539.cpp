#include <bits/stdc++.h>
using namespace std;
int R, C, P, N;
map<int, int> mx;
int maxY;
int main() {
	cin >> R >> C >> P >> N;
	for (int i = 0; i < N; i++) {
		int y, x;
		cin >> y >> x;
		mx[x] = x;
		maxY = max(maxY, y);
	}
	int s = maxY, e = 1e6;
	while (s <= e) {
		int mid = (s + e) / 2, cnt = 0, now = 0;
		auto next = mx.lower_bound(now);
		for (; next != mx.end(); cnt++) {
			now = (*next).second + mid;
			next = mx.lower_bound(now);
		}
		if (cnt <= P) e = mid - 1;
		else s = mid + 1;
	}
	cout << s << "\n";
}