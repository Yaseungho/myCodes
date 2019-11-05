#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> water;
	int N, L, cnt = 0, d = 0;
	cin >> N >> L;
	if (L == 1 || N == 1) {
		cout << N;
		return 0;
	}
	while (N--) {
		int num;
		cin >> num;
		water.push_back(num);
	}
	sort(water.begin(), water.end());
	for (int i = 1; i < water.size(); i++) {
		d += (water[i]- water[i - 1]);
		if (d > L - 1) {
			d = 0;
			cnt++;
		}
	}
	cout << cnt + 1;
	return 0;
}