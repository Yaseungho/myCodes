#include <iostream>
#include <vector>
using namespace std;

vector<long long> vec;

int main() {
	long long N, M, time, Start = 0, End = 10000000000, mid, temp, result = -1;
	cin >> N >> M;
	while (N--) {
		cin >> time;
		vec.push_back(time);
	}
	while (End - Start > 1) {
		mid = (Start + End) / 2;
		temp = 0;
		for (int i = 0; i < vec.size(); i++) {
			temp += vec[i] / mid;
		}
		if (temp < M) End = mid;
		else {
			result = mid;
			Start = mid;
		}
	}
	cout << result;
}