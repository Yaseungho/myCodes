#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> numList;

void func(int last, vector<int> arr) {
	if (arr.size() == m) {
		for (int i : arr) cout << i << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		bool ck = false;
		for (int j : arr) if (j == numList[i]) ck = true;
		if (ck) continue;
		arr.push_back(numList[i]);
		func(i, arr);
		arr.pop_back();
	}
}

int main() {
	cin >> n >> m;
	numList.resize(n);
	for (int i = 0; i < n; i++) cin >> numList[i];
	sort(numList.begin(), numList.end());
	vector<int> temp;
	func(0, temp);
}