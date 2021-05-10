#include <bits/stdc++.h>
using namespace std;
vector<int> vec;

int main() {
	int N, K, res = 0;
	cin >> N >> K;
	vec.resize(N);
	for (int i = 0; i < N; i++) cin >> vec[i];
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < N; i++) {
		int temp = K / vec[i];
		K -= temp * vec[i];
		res += temp;
	}
	cout << res << "\n";
}