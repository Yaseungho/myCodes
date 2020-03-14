#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int> a, const pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	int result = 0, time = 0;
	vector< pair<int, int> > vec;
	for (int i = 0; i < 11; i++) {
		int D, V;
		cin >> D >> V;
		vec.push_back({ D,V });
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < 11; i++) {
		time += vec[i].first;
		result += vec[i].second * 20 + time;
	}
	cout << result << "\n";
}