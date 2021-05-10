#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec;
int N;

bool func(int val) {
	for (int i = 0; i < N; i++) {
		if (val <= vec[i].first - vec[i].second) val += vec[i].second;
		else return 0;
	}
	return 1;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int T, S;
		cin >> T >> S;
		vec.push_back({ S,T });
	}
	sort(vec.begin(), vec.end());
	int s = 0, e = 1e6;
	if (!func(0)) cout << "-1\n";
	else {
		while (s <= e) {
			int mid = (s + e) / 2;
			if (func(mid)) s = mid + 1;
			else e = mid - 1;
		}
		cout << e << "\n";
	}
}