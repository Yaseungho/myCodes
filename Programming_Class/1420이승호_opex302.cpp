#include <iostream>
using namespace std;

class Box {
private:
	double length;
	double width;
	double height;
public:
	Box(double l = 0, double w = 0, double h = 0) : length{ l }, width{ w }, height{ h }{}
	double getVolume(void) {
		return length * width * height;
	}
	void print() {
		cout << "가로: " << length << " 세로: " << width << " 높이: " << height << "\n";
	}
	bool operator==(Box& b2);
};
bool Box::operator==(Box& b2) {
	return b2.getVolume() == this->getVolume();
}

int main() {
	Box b1(10, 10, 20);
	Box b2(20, 10, 10);
	if (b1 == b2) cout << "부피가 동일함\n";
	else cout << "부피가 다름\n";

	Box b3(20, 20, 10);
	if (b1 == b3) cout << "부피가 동일함\n";
	else cout << "부피가 다름\n";

	return 0;
}
