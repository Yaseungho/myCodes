#include <iostream>
#include <vector>
using namespace std;
int N;
char map[100][100];
bool visited[100][100] = { false };
const int Dx[4] = { 1,-1, 0, 0 };
const int Dy[4] = { 0, 0, 1,-1 };


void DFS(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + Dx[i];
		int ny = y + Dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
			if (map[y][x] == map[ny][nx] && !visited[ny][nx]) DFS(ny, nx);
		}
	}
}

int getComponent() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				ret++;
				DFS(i, j);
			}
		}
	}
	return ret;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> map[i][j];
	cout << getComponent() << " ";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'R') map[i][j] = 'G';
			visited[i][j] = false;
		}
	}
	cout << getComponent() << "\n";
}