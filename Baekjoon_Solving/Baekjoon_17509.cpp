#include <bits/stdc++.h>
using namespace std;

int main() {
	int res = 0, time = 0;
	vector<int> vec;
	for (int i = 0; i < 11; i++) {
		int D, V;
		cin >> D >> V;
		vec.push_back(D);
		res += 20 * V;
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < 11; i++) {
		time += vec[i];
		res += time;
	}
	cout << res << "\n";
}