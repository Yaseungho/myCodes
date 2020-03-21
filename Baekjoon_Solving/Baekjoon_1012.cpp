#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector< pair<int, int> > graph[51][51];
bool visited[51][51];
bool map[51][51];
int N, M;//세로,가로

const int Dx[4] = { 0, 0, 1,-1 };
const int Dy[4] = { 1,-1, 0, 0 };

void DFS(int y,int x) {
	visited[y][x] = true;
	for (int i = 0; i < graph[y][x].size(); i++) {
		int ny = graph[y][x][i].first;
		int nx = graph[y][x][i].second;
		if (!visited[ny][nx]) DFS(ny, nx);
	}
}

int cntComponent() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			visited[i][j] = false;
		}
	}
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && map[i][j]) {
				DFS(i, j);
				ret++;
			}
		}
	}
	return ret;
}

void addVoltex() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = j + Dx[k];
				int ny = i + Dy[k];
				if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
					if (map[i][j] && map[ny][nx]) {
						graph[i][j].push_back({ ny,nx });
					}
				}
			}
		}
	}
}

int main() {
	vector<int> results;
	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				graph[i][j].clear();
				map[i][j] = false;
			}
		}
		int K, x, y;
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			map[y][x] = true;
		}
		addVoltex();
		cout << cntComponent() << "\n";
	}
}