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
	Box operator+(const Box& b2);
	Box operator-(const Box& b2);
	Box operator*(const Box& b2);
	Box operator/(const Box& b2);
};
Box Box::operator+(const Box& b2) {
	Box b1;
	b1.height = this->height + b2.height;
	b1.length = this->length + b2.length;
	b1.width = this->width + b2.width;
	return b1;
}
Box Box::operator-(const Box& b2) {
	Box b1;
	b1.height = this->height - b2.height;
	b1.length = this->length - b2.length;
	b1.width = this->width - b2.width;
	return b1;
}
Box Box::operator*(const Box& b2) {
	Box b1;
	b1.height = this->height * b2.height;
	b1.length = this->length * b2.length;
	b1.width = this->width * b2.width;
	return b1;
}
Box Box::operator/(const Box& b2) {
	Box b1;
	b1.height = this->height / b2.height;
	b1.length = this->length / b2.length;
	b1.width = this->width / b2.width;
	return b1;
}

int main() {
	Box b1(25, 30, 15);
	Box b2(10, 20, 10);
	Box temp = b1 + b2;
	temp.print();
	temp = b1 - b2;	
	temp.print();
	temp = b1 * b2;
	temp.print();
	temp = b1 / b2;
	temp.print();
	return 0;
}