#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Temperature {
private:
	int hour;
	double temp;
public:
	Temperature(int h, double t) : hour{ h }, temp{ t }{}
	void print() {
		cout << hour << "시 : 온도 " << temp << "\n";
	}
};
int main() {
	int _hour;
	double _temp;
	ifstream is{ "temp.txt" };
	if (!is) {
		cerr << "파일 오픈 실패\n";
		exit(1);
	}
	vector<Temperature> vec;
	is >> _hour;
	is >> _temp;
	while (is) {
		vec.push_back(Temperature(_hour, _temp));
		is >> _hour;
		is >> _temp;
	}
	for (auto& v : vec) v.print();
	return 0;
}