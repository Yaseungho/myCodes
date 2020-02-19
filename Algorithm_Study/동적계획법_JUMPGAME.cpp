#include <iostream>
using namespace std;

int DP[8][8];
const int map[7][7] = {
	{2,5,1,6,1,4,1},
	{6,1,1,2,2,9,3},
	{7,2,3,2,1,3,1},
	{1,1,3,1,7,1,2},
	{4,1,2,3,4,1,2},
	{3,3,1,2,3,4,1},
	{1,5,2,9,4,7,0}
};

bool jump(int y, int x) {
	if (x == 6 && y == 6) return 1;
	if (6 < x || 6 < y) return 0;
	if (DP[y][x] != -1) return (bool)DP[y][x];
	return DP[y][x] = (jump(y + map[y][x], x) || jump(y, x + map[y][x]));
}

int main() {
	memset(DP, -1, sizeof(DP));
	cout << (jump(0, 0) ? "가능" : "불가능") << "\n";
	return 0;
}