#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[50][50] = { false };
double directions[4];
int Dx[4] = { 1,-1, 0, 0 };
int Dy[4] = { 0, 0,-1, 1 };
//순서대로 동,서,남,북

double result = 0.0;

void solve(double num, int N, int y, int x) {
	visited[y][x] = true;
	if (N == 0) {
		result += num;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + Dx[i];
		int ny = y + Dy[i];
		if (!visited[ny][nx]) {
			solve(num * directions[i], N - 1, ny, nx);
			visited[ny][nx] = false;
		}
	}
}

int main() {
	cout.precision(15);
	int N;
	cin >> N;
	for (int i = 0; i < 4; i++) {
		double temp;
		cin >> temp;
		directions[i] = temp / 100;
	}
	solve(1, N, 25, 25);
	cout << result << "\n";
}