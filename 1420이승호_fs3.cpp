#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int hour;
	double temp;

	ifstream is{ "temp.txt" };
	if (!is) {
		cerr << "���� ���� ����\n";
		exit(1);
	}
	is >> hour;
	is >> temp;
	while (is) {
		cout << hour << "�� : �µ� " << temp << "\n";
		is >> hour;
		is >> temp;
	}
	return 0;
}