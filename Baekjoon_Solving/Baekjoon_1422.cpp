#include <bits/stdc++.h>
using namespace std;
vector<string> vec;

bool compare(const string& a, const string& b) {
	return stoull(a + b) > stoull(b + a);
}

int main() {
	int K, N;
	string max = "0", num;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> num;
		if (stoull(max) < stoull(num)) max = num;
		vec.push_back(num);
	}
	for (int i = 0; i < (N - K); i++) vec.push_back(max);
	sort(vec.begin(), vec.end(), compare);
	for (auto& v : vec) cout << v;
	cout << "\n";
}