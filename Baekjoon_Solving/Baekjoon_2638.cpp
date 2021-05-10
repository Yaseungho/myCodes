#include <bits/stdc++.h>
using namespace std;
int N, M, field[103][103];
int Dx[4] = { 0,-1,0,1 };
int Dy[4] = { 1,0,-1,0 };
vector<pair<int, int>> cheeses;

void BFS() {
	vector<vector<int>> visited(N, vector<int>(M, 0));
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = 1;
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int j = 0; j < 4; j++) {
			int ny = now.first + Dy[j], nx = now.second + Dx[j];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && field[ny][nx] == 0 && !visited[ny][nx]) {
				visited[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
	for (vector<pair<int, int>>::iterator it = cheeses.begin(); it != cheeses.end();) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			int ny = (*it).first + Dy[j], nx = (*it).second + Dx[j];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && visited[ny][nx]) cnt++;
		}
		if (cnt >= 2) {
			field[(*it).first][(*it).second] = 0;
			it = cheeses.erase(it);
		}
		else it++;
	}
}

int main() {
	int res = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> field[i][j];
			if (field[i][j] == 1) cheeses.push_back({ i,j });
		}
	}

	N += 2; M += 2;
	while (!cheeses.empty()) {
		BFS();
		res++;
	}
	cout << res << "\n";
}