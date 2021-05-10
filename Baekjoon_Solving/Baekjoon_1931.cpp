#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec;

int main() {
	int N, res = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		vec.push_back({ e,s });
	}
	sort(vec.begin(), vec.end());
	int now = vec[0].first;
	for (int i = 1; i < N; i++) {
		if (vec[i].second >= now) {
			res++;
			now = vec[i].first;
		}
	}
	cout << res << "\n";
}