#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	char *buffer1, *buffer2;
	int length, i;
	fstream os1{ "temp1.txt", ios::in | ios::out};
	if (!os1) {
		cerr << "파일 오픈에 실패하였습니다.\n";
		exit(1);
	}
	fstream os2{ "temp2.txt", ios::in | ios::out };
	if (!os2) {
		cerr << "파일 오픈에 실패하였습니다.\n";
		exit(1);
	}
	os1.seekg(0, ios::end);
	os2.seekg(0, ios::end);
	if (os1.tellg() == os2.tellg()) {
		length = os1.tellg();
		length++;
		buffer1 = new char[length];
		buffer2 = new char[length];
		os1.seekg(0, ios::beg);
		os2.seekg(0, ios::beg);
		os1.read(buffer1, length);
		os2.read(buffer2, length);
		for (i = 0; i < length; i++) {
			if (buffer1[i] != buffer2[i]) break;
		}
		if (i == length) cout << "표절입니다.\n";
		else cout << "표절이 아닙니다.\n";
	}
	else cout << "표절이 아닙니다.\n";
	return 0;
}