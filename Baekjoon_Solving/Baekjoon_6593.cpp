#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int building[31][31][31];
bool visited[31][31][31];
int mx, my, mz;
int sx, sy, sz;
int ex, ey, ez;

const int Dx[6] = {1,-1,0,0,0,0};
const int Dy[6] = {0,0,1,-1,0,0};
const int Dz[6] = {0,0,0,0,1,-1};

class Vector3
{
public :
	int x, y, z;
	Vector3(int _x, int _y, int _z) :
		x{ _x }, y{ _y }, z{ _z } {}
};

int Bfs() {
	queue<Vector3> q;
	q.push(Vector3(sx, sy, sz));
	visited[sz][sy][sx] = true;
	int depth = 1;
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			Vector3 now = q.front();
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = now.x + Dx[i];
				int ny = now.y + Dy[i];
				int nz = now.z + Dz[i];
				if (nx == ex && ny == ey && nz == ez) return depth;
				if (0 <= nx && nx < mx &&
					0 <= ny && ny < my &&
					0 <= nz && nz < mz && 
					building[nz][ny][nx] == 0 && !visited[nz][ny][nx]) {
					visited[nz][ny][nx] = true;
					q.push(Vector3(nx, ny, nz));
				}
			}
		}
		depth++;
	}
	return -1;
}

int main() {
	while (1) {
		memset(visited, false, sizeof(visited));
		memset(building, 0, sizeof(building));
		cin >> mz >> my >> mx;
		if (mz == 0 && my == 0 && mx == 0) break;
		for (int i = 0; i < mz; i++) {
			for (int j = 0; j < my; j++) {
				for (int k = 0; k < mx; k++) {
					char temp;
					cin >> temp;
					if (temp == 'S') {
						sz = i;
						sy = j;
						sx = k;
					}
					else if (temp == '.') {
						building[i][j][k] = 0;
					}
					else if (temp == '#') {
						building[i][j][k] = 1;
					}
					else if (temp == 'E') {
						ez = i;
						ey = j;
						ex = k;
					}
				}
			}
		}
		int res = Bfs();
		if (res == -1) cout << "Trapped!\n";
		else cout << "Escaped in " << res << " minute(s).\n";
	}
}