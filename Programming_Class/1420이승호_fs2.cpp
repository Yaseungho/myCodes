#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int sum = 0, num;

	ifstream is{ "sum.txt" };
	if (!is) {
		cerr << "���� ���� ����\n";
		exit(1);
	}
	while (is) {
		is >> num;
		sum += num;
	}
	cout << "���Ͽ� ����� ������ ���� " << sum << "\n";
	return 0;
}