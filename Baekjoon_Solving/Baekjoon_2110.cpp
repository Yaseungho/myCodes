#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long C;
vector<long long> vec;

bool func(long long D) {
	int cnt = 1, loc = vec[0], i = 1;
	while (cnt != C) {
		if (i == vec.size()) return false;
		if (loc + D <= vec[i]) {
			cnt++;
			loc = vec[i];
			i++;
		}
		else i++;
	}
	return true;
}

int main() {
	long long N, x, Start = 0, End = 1000000000, mid, result;
	bool temp;
	cin >> N >> C;
	while (N--) {
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	while (End - Start > 1) {
		mid = (Start + End) / 2;
		temp = func(mid);
		if (temp) {
			result = mid;
			Start = mid;
		}
		else End = mid;
	}
	cout << result;
}