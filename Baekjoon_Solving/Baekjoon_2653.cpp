#include <bits/stdc++.h>
using namespace std;
int N;
bool field[101][101], visited[101];

vector<int> Search(int n) {
	visited[n] = 1;
	vector<int> group;
	group.push_back(n);
	for (int i = 0; i < N; i++) {
		bool flag = 1;
		if (visited[i]) continue;
		for (int j = 0; j < group.size(); j++) if (field[i][group[j]] == 1) flag = 0;
		if (flag) {
			visited[i] = 1;
			group.push_back(i);
		}
	}
	return group;
}

int main() {
	vector<vector<int>> res;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> field[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			vector<int> temp = Search(i);
			res.push_back(temp);
			if (temp.size() < 2) {
				cout << 0 << "\n";
				return 0;
			}
		}
	}
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++) {
		sort(res[i].begin(), res[i].end());
		for (int v : res[i]) cout << v + 1 << " ";
		cout << "\n";
	}
}