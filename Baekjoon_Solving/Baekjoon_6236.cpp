#include <iostream>
#include <vector>
#define IMPOSSIBLE 999999999
using namespace std;

vector<long long> vec;

long long func(long long length) {
	long long ret = 0, temp = 0;
	for (long long i = 0; i < vec.size(); i++) {
		if (vec[i] > length) return IMPOSSIBLE;
		if (temp + vec[i] > length) {
			temp = vec[i];
			ret++;
		}
		else temp += vec[i];
	}
	return ret + 1;
}

int main() {
	long long N, M, time, Start = 0, End = 1000000000, mid, temp, result = -1;
	cin >> N >> M;
	while (N--) {
		cin >> time;
		vec.push_back(time);
	}
	while (End - Start > 1) {
		mid = (Start + End) / 2;
		temp = func(mid);
		if (temp > M) Start = mid;
		else {
			result = mid;
			End = mid;
		}
	}
	cout << result;
}