#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll N, M;
	cin >> N >> M;
	vector<ll> A(N);
	vector<ll> B(M);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < M; i++) cin >> B[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	ll i = 0, j = 0, cnt = 0;
	while (1) {
		if (i == N || j == M) break;
		if (A[i] == B[j]) {
			i++; j++; cnt++;
		}
		else if (A[i] < B[j]) i++;
		else j++;
	}
	cout << M + N - 2 * cnt << "\n";
}