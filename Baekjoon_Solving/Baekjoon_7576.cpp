#include <bits/stdc++.h>
using namespace std;
int adj[1001][1001], n, m, res = -1;
const int Dx[4] = { 0,1,-1,0 };
const int Dy[4] = { 1,0,0,-1 };
queue<pair<int,int>> q;
int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> adj[i][j];
			if (adj[i][j] == 1) q.push({ i,j });
		}
	}
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			pair<int, int> now = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = now.first + Dy[j];
				int nx = now.second + Dx[j];
				if (0 <= nx && nx < m && 0 <= ny && ny < n && adj[ny][nx] == 0) {
					adj[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
		}
		res++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (adj[i][j] == 0) {
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << res << "\n";
}