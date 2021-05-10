#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	ll N, S, s = 0, e = 0, sum = 0, res = 2e9;
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sum = 0;
	while (1) {
		if (sum >= S) {
			res = min(res, e - s);
			sum -= arr[s++];
		}
		else if (e == N) break; 
		else sum += arr[e++];
	}
	cout << (res == 2e9 ? 0 : res) << "\n";
}