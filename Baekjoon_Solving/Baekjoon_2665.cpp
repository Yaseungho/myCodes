#include <bits/stdc++.h>
using namespace std;
int N;
int Dx[4] = { 0,-1,0,1 };
int Dy[4] = { 1,0,-1,0 };
string field[51];

int Solve() {
	vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
	priority_queue<pair<int, pair<int, int>>> pq;
	dist[0][0] = 0;
	pq.push({0,{0,0}});
	while (!pq.empty()) {
		int cost = -(pq.top().first);
		pair<int, int> now = pq.top().second;
		pq.pop();
		if (dist[now.first][now.second] < cost) continue;
		for (int j = 0; j < 4; j++) {
			int ny = now.first + Dy[j], nx = now.second + Dx[j];
			if (0 <= ny && ny < N && 0 <= nx && nx < N) {
				int nCost = field[ny][nx] == '0' ? cost + 1 : cost;
				if (dist[ny][nx] > nCost) {
					dist[ny][nx] = nCost;
					pq.push({ -nCost, {ny, nx} });
				}

			}
		}
	}
	return dist[N - 1][N - 1];
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> field[i];
	cout << Solve() << "\n";
}