#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string temp;
	int num = 0;
	fstream os{ "input.txt", ios::in | ios::out};
	if (!os) {
		cerr << "파일 오픈에 실패하였습니다.\n";
		exit(1);
	}
	for (; os; os >> temp, num++) {}
	cout << "단어의 수: " << num;
	return 0;
}