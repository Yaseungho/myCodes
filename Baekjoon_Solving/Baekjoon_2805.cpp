#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vec;
	long long N, M, h, Start = 0, End = 1000000000, mid, sum;
	cin >> N >> M;
	while (N--) {
		cin >> h;
		vec.push_back(h);
	}
	while (End - Start > 1) {
		sum = 0;
		mid = (Start + End) / 2;
		for (int i = 0; i < vec.size(); i++) if(vec[i] > mid) sum += vec[i] - mid;
		if (sum >= M) Start = mid;
		else End = mid;
	}
	cout << Start;
	return 0;
}