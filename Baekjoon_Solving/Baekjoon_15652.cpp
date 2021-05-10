#include <bits/stdc++.h>
using namespace std;

int n, m;

void func(int last, vector<int> arr) {
	if (arr.size() == m) {
		for (int i : arr) cout << i << " ";
		cout << "\n";
		return;
	}
	for (int i = last; i <= n; i++) {
		arr.push_back(i);
		func(i, arr);
		arr.pop_back();
	}
}

int main() {
	cin >> n >> m;
	vector<int> temp;
	func(1, temp);
}