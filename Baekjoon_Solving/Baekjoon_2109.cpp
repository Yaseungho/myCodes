#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> lectures;
bool arr[10001];

int main() {
	int N, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int p, d;
		cin >> p >> d;
		lectures.push_back({ p,d });
	}
	sort(lectures.begin(), lectures.end(), greater<pair<int,int>>());
	for (int i = 0; i < N; i++) {
		for (int j = lectures[i].second; j > 0; j--) {
			if (arr[j] == 0) {
				arr[j] = 1;
				sum += lectures[i].first;
				break;
			}
		}
	}
	cout << sum << "\n";
}