#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

bool compare(const pair<int, int> a, const pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	vector< pair<int, int> > vec;
	priority_queue< int, vector<int>, greater<int> > lecture;
	int n, i, j;
	bool is = true;
	cin >> n;
	while (n--) {
		int t1, t2;
		cin >> t1 >> t2;
		vec.push_back(make_pair(t1, t2));
	}
	sort(vec.begin(), vec.end(), compare);
	lecture.push(vec[0].second);
	for (i = 1; i < vec.size(); i++) {
		pair<int, int> vec_i = vec[i];
		if (lecture.top() > vec_i.first) lecture.push(vec_i.second);
		else {
			lecture.pop();
			lecture.push(vec_i.second);
		}
	}
	cout << lecture.size();
	return 0;
}