#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vec;
	long long N, M, h, Start = 0, End = 1000000000, mid, sum, sum2 = 0, max = 0;
	cin >> N;
	while (N--) {
		cin >> h;
		if (max < h) max = h;
		vec.push_back(h);
		sum2 += h;
	}
	cin >> M;
	while (End - Start > 1) {
		sum = 0;
		mid = (Start + End) / 2;
		for (int i = 0; i < vec.size(); i++) {
			if (mid < vec[i]) sum += mid;
			else sum += vec[i];
		}
		if (sum <= M) Start = mid;
		else End = mid;
	}
	if (sum2 <= M) cout << max;
	else cout << Start;
	return 0;
}