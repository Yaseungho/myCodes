#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string temp;
	int num = 0;
	fstream os{ "input.txt", ios::in | ios::out};
	if (!os) {
		cerr << "���� ���¿� �����Ͽ����ϴ�.\n";
		exit(1);
	}
	for (; os; os >> temp, num++) {}
	cout << "�ܾ��� ��: " << num;
	return 0;
}