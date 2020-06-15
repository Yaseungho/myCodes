#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char graph[102][102];
bool visited[102][102] = { false };
int result = -1;

void BFS() {
	queue<pair<int,int>> q;
	q.push({ 1, 1 });
	visited[1][1] = true;

	int depth = 1;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			pair<int, int> now = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = now.second + dx[j];
				int ny = now.first + dy[j];
				if (!visited[ny][nx] && graph[ny][nx] != '0') {
					if (nx == m && ny == n) result = depth + 1;
					visited[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
		depth++;
	}
}

int main() {
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			graph[i][j] = '0';
		}
	}
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			graph[i][j] = str[j - 1];
		}
	}
	BFS();
	cout << result << "\n";
}