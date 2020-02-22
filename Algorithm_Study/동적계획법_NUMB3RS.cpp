#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
double DP[101][51]; //DP[a][b] = a일동안 b에서부터 이동했을 때 목표 지점에 도달할 확률
bool map[50][50];
int Q, N;

double func(int day, int from) {
	if (!day) {
		if (from == Q) return 1;
		else return 0;
	}
	if (DP[day][from] != -1) return DP[day][from];
	double ret = 0.0;
	double mother = 0.0;
	for (int i = 0; i < N; i++) if (map[from][i]) mother += 1;
	for (int i = 0; i < N; i++) {
		if (map[from][i]) ret += (1.0/mother) * func(day - 1, i);
	}
	return DP[day][from] = ret;
}

int main() {
	cout.precision(8);
	int C;
	cin >> C;
	while (C--) {
		vector<double> results;
		int D, P, T;
		//지난 일 수, 교도소가 있는 마을의 번호, 검사할 마을의 수
		cin >> N >> D >> P;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		cin >> T;
		for (int i = 0; i < T; i++) {
			for (int i = 0; i < 101; i++) for (int j = 0; j < 51; j++) DP[i][j] = -1;
			cin >> Q;
			results.push_back(func(D, P));
		}
		for (double& v : results) {
			cout << v << " ";
		} cout << "\n";
	}
}