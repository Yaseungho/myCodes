#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int i = 1;
	string temp1, temp2, temp3;
	ifstream is{ "scores.txt" };
	if (!is) {
		cerr << "���� ���¿� �����Ͽ����ϴ�" << endl;
		exit(1);
	}
	ofstream os{ "result.txt" };
	if (!os) {
		cerr << "���� ���¿� �����Ͽ����ϴ�" << endl;
		exit(1);
	}
	is >> temp1;
	is >> temp2;
	is >> temp3;
	while (is) {
		os << i++ << ": " << temp1 << " " << temp2 << " " << temp3 << " \n";
		is >> temp1;
		is >> temp2;
		is >> temp3;
	}
	return 0;
}