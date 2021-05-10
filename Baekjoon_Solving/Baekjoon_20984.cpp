#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[200001], arrleft[200001], arrright[200001];

int main() {
	ll N, res = 0;
	cin >> N;
	for (ll i = 0; i < N; i++) cin >> arr[i];
	ll cnt = 0, nowMax = arr[0];
	arrleft[0] = arrright[N - 1] = 0;
	for (ll i = 1; i < N; i++) {
		if (nowMax >= arr[i] + cnt) {
			nowMax++; 
			cnt += nowMax - arr[i] - cnt;
			arrleft[i] = cnt;
		}
		else {
			nowMax = arr[i] + cnt;
			arrleft[i] = cnt;
		}
	}
	nowMax = arr[N - 1]; cnt = 0;
	for (ll i = N - 2; i >= 0; i--) {
		if (nowMax >= arr[i] + cnt) {
			nowMax++;
			cnt += nowMax - arr[i] - cnt;
			arrright[i] = cnt;
		}
		else {
			nowMax = arr[i] + cnt;
			arrright[i] = cnt;
		}
	}
	res = max(arrright[0], arrleft[0]);
	for (ll i = 1; i < N; i++) res = min(res, max(arrright[i], arrleft[i]));
	cout << res << "\n";
}