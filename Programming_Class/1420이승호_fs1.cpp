#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream os{ "sum.txt" };
	if (!os) {
		cerr << "���� ���� ����\n";
		exit(1);
	}
	for (int i = 0; i <= 10; i++) {
		os << i << " ";
	}
	return 0;
}