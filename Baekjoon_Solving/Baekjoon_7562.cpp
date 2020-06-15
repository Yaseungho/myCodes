#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int n;
int dx[8] = { 2,1,-1,-2,-1,-2, 2, 1 };
int dy[8] = { 1,2,-2,-1, 2, 1,-1,-2 };
bool visited[302][302] = { false };
int result;
void BFS(int x1, int x2, int y1, int y2) {
	queue<pair<int,int>> q;
	q.push({ y1, x1 });
	visited[y1][x1] = true;
	int depth = 1;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			pair<int, int> now = q.front();
			q.pop();
			for (int j = 0; j < 8; j++) {
				int nx = now.second + dx[j];
				int ny = now.first + dy[j];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (!visited[ny][nx]) {
						if (ny == y2 && nx == x2) result = depth;
						visited[ny][nx] = true;
						q.push({ ny,nx });
					}
				}
			}
		}
		depth++;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		result = 0;
		memset(visited, 0, sizeof(visited));
		int x1, x2, y1, y2;
		cin >> n >> x1 >> y1 >> x2 >> y2;
		BFS(x1, x2, y1, y2);
		cout << result << "\n";
	}
}