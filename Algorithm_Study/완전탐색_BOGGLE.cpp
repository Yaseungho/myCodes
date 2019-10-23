#include <iostream>
#include <string>
using namespace std;

char board[5][5] = {
{ 'D','R','D','C','J'},
{ 'Y','A','I','E','N'},
{ 'C','K','N','G','P'},
{ 'U','E','R','V','Y'},
{ 'E','F','L','O','P'}
};
 
const int dx[8] = { -1,-1,-1, 1,1,1, 0,0 };
const int dy[8] = { -1, 0, 1,-1,0,1,-1,1 };

bool hasWord(int y, int x,const string& word) {
	if (x < 0 || x > 4 || y < 0 || y > 4) return false;
	if (board[y][x] != word[0]) return false;
	if (word.size() == 1) return true;
	for (int direction = 0; direction < 8; direction++) {
		int nextY = y + dy[direction], nextX = x + dx[direction];
		if (hasWord(nextY, nextX, word.substr(1))) return true;
	} return false;
}

int main() {
	cout << (hasWord(4, 1, "FUCKING") ? "YES\n" : "NO\n");
	return 0;
}