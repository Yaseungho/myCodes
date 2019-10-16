#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	char temp;
	int length;
	fstream os{ "words.txt", ios::in | ios::out};
	if (!os) {
		cerr << "파일 오픈에 실패하였습니다.\n";
		exit(1);
	}
	os.seekg(0, ios::end);
	length = os.tellg();
	os.seekg(0, ios::beg);
	while (os.tellg() != length) {
		os >> temp;
		cout << temp;
		if (temp >= 'a' && temp <= 'z') temp -= 32;
		if (temp == 'A' || temp == 'E' || temp == 'I' || temp == 'O' || temp == 'U') {
			os.seekg(-1, ios::cur);
			os << '*';
			os.seekg(os.tellg(), ios::beg);
			cout << "바뀜";
		}
	}
	return 0;
}