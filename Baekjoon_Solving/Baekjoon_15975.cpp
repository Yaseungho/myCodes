#include <bits/stdc++.h>
using namespace std;
vector<pair<int, long long>> vec;//color, pos

int main() {
	int N;
	long long res = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, c;
		cin >> x >> c;
		vec.push_back({ c,x });
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		long long val = 2e10;
		if (i > 0 && vec[i].first == vec[i - 1].first) val = vec[i].second - vec[i - 1].second;
		if (i < N - 1 && vec[i].first == vec[i + 1].first) val = min(val, vec[i + 1].second - vec[i].second);
		if(val != 2e10) res += val;
	}
	cout << res << "\n";
}