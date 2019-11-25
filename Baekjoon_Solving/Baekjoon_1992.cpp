#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> vec;

bool isSame(int startX, int startY, int length) {
	int temp = vec[startY][startX];
	for (int i = startY; i < startY + length; i++) {
		for (int j = startX; j < startX + length; j++) {
			if (temp != vec[i][j]) return false;
			temp = vec[i][j];
		}
	}
	return true;
}

void Quad(int startX, int startY, int length) {
	if (isSame(startX, startY, length) || length <= 1) cout << vec[startY][startX];
	else {
		cout << "(";
		length /= 2;
		Quad(startX, startY, length);
		Quad(startX + length, startY, length);
		Quad(startX, startY + length, length);
		Quad(startX + length, startY + length, length);
		cout << ")";
	}
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		vec.push_back(temp);
	}
	Quad(0, 0, n);
	return 0;
}