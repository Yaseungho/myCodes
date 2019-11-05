#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt = 0, S;
vector<int> vec;

void cntPlus(vector<int> picked) {
	int sum = 0;
	for (int& v : picked) sum += vec[v];
	if (sum == S) cnt++;
	return;
}

void pick(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) {cntPlus(picked); return; }
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; next++) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

int main() {
	int N;
	cin >> N >> S;
	int n = N;
	while (N--) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
	for (int i = n; i > 0; i--) {
		vector<int> temp;
		pick(n, temp, i);
	}
	cout << cnt;
	return 0;
}