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
	bool operator<(Box& b2);
};

bool Box::operator<(Box& b2) {
	return this->getVolume() < b2.getVolume();
}

int main() {
	Box b1(10, 10, 20);
	Box b2(10, 10, 10);
	if (b1 < b2) cout << "b2가 더 크다(참)\n";
	else cout << "b1이 더 크다(거짓)\n";

	Box b3(20, 20, 20);
	if (b1 < b3) cout << "b3이 더 크다(참)\n";
	else cout << "b1이 더 크다(거짓)\n";

	return 0;
}