#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector< pair<int, int> > graph[101][101];
bool visited[101][101] = { false };
bool map[101][101] = { false };
int N, M;//세로,가로

const int Dx[4] = { 0, 0, 1,-1 };
const int Dy[4] = { 1,-1, 0, 0 };

int DFS(int y,int x, int& call) {
	call++;
	visited[y][x] = true;
	for (int i = 0; i < graph[y][x].size(); i++) {
		int ny = graph[y][x][i].first;
		int nx = graph[y][x][i].second;
		if (!visited[ny][nx]) DFS(ny, nx, call);
	}
	return call;
}

int getMaxComponent() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visited[i][j] && map[i][j]) {
				int temp = 0;
				DFS(i, j, temp);
				ret = max(temp, ret);
			}
		}
	}
	return ret;
}

void addVoltex() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = j + Dx[k];
				int ny = i + Dy[k];
				if (nx > 0 && ny > 0 && nx <= M && ny <= N) {
					if (map[i][j] && map[ny][nx]){
						graph[i][j].push_back({ ny,nx });
					}
				}
			}
		}
	}
}

int main() {
	int K, x, y;
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> y >> x;
		map[y][x] = true;
	}
	addVoltex();
	cout << getMaxComponent();
}