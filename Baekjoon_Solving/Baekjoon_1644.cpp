#include <bits/stdc++.h>
using namespace std;
bool isPrime[4000001];
vector<int> primes;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	for (int i = 2; i < 4000000; i++) isPrime[i] = true;
	for (int i = 2; i < 4000000; i++) {
		if (!isPrime[i]) continue;
		for (int j = i * 2; j <= 4000000; j += i) isPrime[j] = false;
	}
	for (int i = 0; i < 4000000; i++) if (isPrime[i]) primes.push_back(i);
	int N, res = 0, s = 0, e = 0, sum = 0;
	cin >> N;
	while (1) {
		if (N <= sum) sum -= primes[s++];
		else if (e == primes.size()) break;
		else sum += primes[e++];
		if (N == sum) res++;
	}
	cout << res << "\n";
}