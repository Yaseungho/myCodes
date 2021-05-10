#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	double n;
	cin >> n;
	ll num = n * 1e9, div = 1e9;
	while (1) {
		ll k = gcd(num, div);
		if (k == 1) break;
		num /= k; div /= k;
	}
	vector<int> res(7);
	res[num / div] = div - (num % div);
	res[num / div + 1] = num % div;
	for (int i = 1; i <= 5; i++) cout << res[i] << " ";
	cout << "\n";
}