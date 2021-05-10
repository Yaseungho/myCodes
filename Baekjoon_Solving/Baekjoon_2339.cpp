#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<vector<int>> vec;
int N;

int divide(int sx, int sy, int ex, int ey, bool is) {//is가 0일시 가로, 1일시 세로 자르기
	int N1 = 0, N2 = 0;
	if (sx < 0 || sy < 0 || ex > N || ey > N) return true;
	vector<pair<int, int>> coordinates;//x,y 저장
	for (int i = sy; i < ey; i++) {
		for (int j = sx; j < ex; j++) {
			if (vec[i][j] == 1) {
				N1++;
				coordinates.push_back({ j, i });
			}
			else if (vec[i][j] == 2) {
				N2++;
			}
		}
	}

	if (!N1) {//(기저 사례)범위에 불순물이 없을 경우
		if (N2 == 1) return 1;
		else return 0;
	}
	else {//범위에 불순물이 있을 경우
		int res = 0;
		for (int i = 0; i < N1; i++) {
			int nx = coordinates[i].first;
			int ny = coordinates[i].second;
			if (is) {//가로 자르기
				int temp = 0, temp2 = 0;
				for (int k = sx; k < ex; k++) {
					if (vec[ny][k] == 1) temp++;
					if (vec[ny][k] == 2) temp2 = 1;
				}
				if (temp > 1 || temp2) continue;
				if (ny - sy < 1 || ey - ny < 1) continue;
				res += divide(sx, sy, ex, ny, false) * divide(sx, ny + 1, ex, ey, false);
			}
			else {//세로 자르기
				int temp = 0, temp2 = 0;
				for (int k = sy; k < ey; k++) {
					if (vec[k][nx] == 1) temp++;
					if (vec[k][nx] == 2) temp2++;
				}
				if (temp > 1 || temp2) continue;
				if (nx - sx < 1 || ex - nx < 1) continue;
				res += divide(sx, sy, nx, ey, true) * divide(nx + 1, sy, ex, ey, true);
			}
		}
		return res;
	}
	return 0;
}

int main() {

	cin >> N;
	int num;
	vector<int> temp;
	for (int i = 0; i < N; i++) {
		vec.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			vec[i].push_back(num);
		}
	}

	int result = divide(0, 0, N, N, true) + divide(0, 0, N, N, false);
	if (result == 0) cout << "-1\n";
	else cout << result << "\n";
}