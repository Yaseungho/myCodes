#include <iostream>
#include <algorithm>
using namespace std;
long long N;
long long func(long long key) {
	long long ret = 0;
	for (long long i = 1; i <= N; i++) {
		ret += min(N, key / i);
	}
	return ret;
}

int main() {
	long long K, Start = 0, End = 10000000000, mid, result = 0;
	cin >> N >> K;
	while (End - Start > 1) {
		mid = (Start + End) / 2;
		if (func(mid) < K) Start = mid;
		else {
			result = mid;
			End = mid;
		}
	}
	cout << result;
	return 0;
}