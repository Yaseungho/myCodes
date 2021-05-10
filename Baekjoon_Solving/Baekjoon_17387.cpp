#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
struct line {
	ll x1, y1, x2, y2;
};

ll CCW(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll ret = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (ret < 0) return -1;
	else if (ret > 0) return 1;
	else return 0;
}

bool isCrossed (line a, line b) {
	ll res1 = CCW(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1) * CCW(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2);
	ll res2 = CCW(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1) * CCW(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2);
	if (res1 <= 0 && res2 <= 0) {
		if (!res1 && !res2)
			return (max(a.x1, a.x2) >= min(b.x1, b.x2) && max(a.y1, a.y2) >= min(b.y1, b.y2) &&
				max(b.x1, b.x2) >= min(a.x1, a.x2) && max(b.y1, b.y2) >= min(a.y1, a.y2));
		else return true;
	}
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	line a, b;
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	cout << (isCrossed(a, b) ? 1 : 0) << "\n";
}