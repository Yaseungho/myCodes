#include <bits/stdc++.h>
using namespace std;
string field[51];
bool visited[51][51][2];
int Dx[8] = { 1,0,-1,0,1,1,-1,-1 };
int Dy[8] = { 0,1,0,-1,1,-1,1,-1 };
struct status {
	int y, x;
	bool is;//¼¼·Î¸é true
};
int N;
status st, goal;
bool s = 1, g = 1;

int BFS() {
	int cnt = 0;
	queue<status> q;
	visited[st.y][st.x][st.is] = 1;
	q.push(st);
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			status now = q.front();
			if (now.x == goal.x && now.y == goal.y && now.is == goal.is) return cnt;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = now.y + Dy[j], nx = now.x + Dx[j];
				if (now.is &&
					0 <= nx && nx < N && 1 <= ny && ny < N - 1 &&
					field[ny - 1][nx] != '1' && field[ny][nx] != '1' && field[ny + 1][nx] != '1' && !visited[ny][nx][1]) {
					visited[ny][nx][1] = 1;
					q.push(status{ ny, nx, 1 });
				}
				else if (!now.is &&
					1 <= nx && nx < N - 1 && 0 <= ny && ny < N &&
					field[ny][nx - 1] != '1' && field[ny][nx] != '1' && field[ny][nx + 1] != '1' && !visited[ny][nx][0]) {
					visited[ny][nx][0] = 1;
					q.push(status{ ny, nx, 0 });
				}
			}
			bool check = 1;
			for (int j = 0; j < 8; j++) {
				int ny = now.y + Dy[j], nx = now.x + Dx[j];
				if (0 <= nx && nx < N && 0 <= ny && ny < N && field[ny][nx] != '1') {}
				else check = 0;
			}
			if (check && !visited[now.y][now.x][!now.is]) {
				visited[now.y][now.x][!now.is] = 1;
				q.push(status{ now.y, now.x, !now.is });
			}
		}
		cnt++;
	}
	return 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> field[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < field[i].size(); j++) {
			if (field[i][j] == 'B' && s) {
				s = 0;
				if (i + 1 < N && field[i + 1][j] == 'B') st = status{ i + 1, j, 1 };
				else st = status{ i, j + 1, 0 };
			}
			if (field[i][j] == 'E' && g) {
				g = 0;
				if (i + 1 < N && field[i + 1][j] == 'E') goal = status{ i + 1, j, 1 };
				else goal = status{ i, j + 1, 0 };
			}
		}
	}
	cout << BFS() << "\n";
}