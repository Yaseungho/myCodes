#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	char temp;
	int length;
	fstream os{ "words.txt", ios::in | ios::out};
	if (!os) {
		cerr << "���� ���¿� �����Ͽ����ϴ�.\n";
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
			cout << "�ٲ�";
		}
	}
	return 0;
}