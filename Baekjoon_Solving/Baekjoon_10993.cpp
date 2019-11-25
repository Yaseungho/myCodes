#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<vector<bool>> vec;

void draw(int sx, int sy, int ex, int ey, bool is) {//is가 참이면 정삼각형, 거짓이면 역삼각형
	if (ex - sx <= 5 && ey - sy <= 3) {
		for (int i = 0; i < 5; i++) vec[sy][sx + i] = 1;
		vec[sy + 1][sx + 1] = 1;
		vec[sy + 1][sx + 2] = 1;
		vec[sy + 1][sx + 3] = 1;
		vec[sy + 2][sx + 2] = 1;
	}
	else {
		if (is) {//정삼각형
			int newsx = 0, newex = 0, newsy = 0;
			for (int i = 0; i < (ey - sy); i++) {
				if (i == (ey - sy) / 2) {
					newsx = sx + i + 1;
					newex = ex - i - 1;
					newsy = ey - i - 1;
				}
				vec[ey - i - 1][ex - i - 1] = 1;
				vec[ey - i - 1][sx + i] = 1;
			}
			for (int i = 0; i < (ex - sx); i++) {
				vec[ey - 1][sx + i] = 1;
			}
			draw(newsx, newsy, newex, ey - 1, false);
		}
		else {//역삼각형
			int newsx = 0, newex = 0, newey = 0;
			for (int i = 0; i < (ey - sy); i++) {
				if (i  == (ey - sy) / 2) {
					newsx = sx + i + 1;
					newex = ex - i - 1;
					newey = sy + i + 1;
				}
				vec[sy + i][sx + i] = 1;
				vec[sy + i][ex - i - 1] = 1;
			}
			for (int i = 0; i < (ex - sx); i++) {
				vec[sy][sx + i] = 1;
			}
			draw(newsx, sy + 1 , newex, newey, true);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int Darr[11] = { 0,1,5,13,29,61,125,253,509,1021,2045 };
	int N;
	cin >> N;
	if (N == 1) {
		cout << "*\n"; 
		return 0;
	}
	int x = Darr[N];
	int y = (int)pow(2, N) - 1;
	for (int i = 0; i < y; i++) {
		vector<bool> temp;
		vec.push_back(temp);
	}
	for (int i = 0; i < y; i++) 
		for (int j = 0; j < x; j++) 
			vec[i].push_back(0);

	draw(0, 0, x, y, (N % 2 ? true : false));
	if (N % 2) {
		int temp = x - y + 1;
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < temp; j++) {
				cout << (vec[i][j] ? "*" : " ");
			}
			cout << " \n";
			temp++;
		}

	}
	else {
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				cout << (vec[i][j] ? "*" : " ");
			}
			cout << " \n";
			x--;
		}
	}
	return 0;
}