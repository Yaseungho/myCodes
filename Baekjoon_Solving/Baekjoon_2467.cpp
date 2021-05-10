#include <bits/stdc++.h>
using namespace std;
int arr[100001];

int sum(int a, int b) {
	return abs(arr[a] + arr[b]);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	int N, s, e, m = 2e9, resl = -1, resr = -1;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	s = 0, e = N - 1;
	while (s != e && s != N - 1 && e != 0) {
		if (m > sum(s,e)) {
			resl = arr[s];
			resr = arr[e];
			m = sum(s, e);
		}
		if (sum(s, e) >= sum(s + 1, e)) s++;
		else if (sum(s, e) >= sum(s, e - 1)) e--;
		else {
			s++;
			e--;
		}
	}
	cout << resl << " " << resr << "\n";
}