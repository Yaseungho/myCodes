#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int sum = 0, num;

	ifstream is{ "sum.txt" };
	if (!is) {
		cerr << "파일 오픈 실패\n";
		exit(1);
	}
	while (is) {
		is >> num;
		sum += num;
	}
	cout << "파일에 저장된 정수의 합은 " << sum << "\n";
	return 0;
}