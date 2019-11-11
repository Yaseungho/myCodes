#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(const pair<long long, long long> a, const pair<long long, long long> b){
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	vector<pair<long long, long long>> vec;
	int n, cnt = 0;
	cin >> n;
	while (n--) {
		int t1, t2;
		cin >> t1 >> t2;
		vec.push_back(make_pair(t1, t2));
	}
	sort(vec.begin(), vec.end(), compare);
	long long temp = vec[0].second;
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i].first >= temp) {
			cnt++;
			temp = vec[i].second;
		}
	}
	cout << cnt + 1;
	return 0;
}