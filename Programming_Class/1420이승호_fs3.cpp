#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int hour;
	double temp;

	ifstream is{ "temp.txt" };
	if (!is) {
		cerr << "파일 오픈 실패\n";
		exit(1);
	}
	is >> hour;
	is >> temp;
	while (is) {
		cout << hour << "시 : 온도 " << temp << "\n";
		is >> hour;
		is >> temp;
	}
	return 0;
}