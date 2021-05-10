#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> vec;

int main() {
	int N, res, now = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int T, S;
		cin >> T >> S;
		vec.push_back({ S,T });
	}
	sort(vec.begin(), vec.end());
	res = vec[0].first - vec[0].second;
	for (int i = 0; i < N; i + ) {
		if (now <= vec[i].second - vec[i].first) now = vec[i].second;
		else {
			cout << "-1\n";
			return 0;
		}
	}
	cout << res << "\n";
}