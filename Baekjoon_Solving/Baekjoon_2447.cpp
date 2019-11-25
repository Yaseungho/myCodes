#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> vec;

void draw(int startX, int startY, int length) {
	if (length == 1) vec[startY][startX] = 1;
	else {
		length /= 3;
		draw(startX, startY, length);
		draw(startX + length, startY, length);
		draw(startX + length + length, startY, length);
		draw(startX, startY + length, length);
		draw(startX + length + length, startY + length, length);
		draw(startX, startY + length + length, length);
		draw(startX + length, startY + length + length, length);
		draw(startX + length + length, startY + length + length, length);
	}
}

int main() {
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<bool> temp;
		vec.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vec[i].push_back(0);
		}
	}
	draw(0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (vec[i][j] ? "*" : " ");
		} cout << "\n";
	}
	return 0;
}