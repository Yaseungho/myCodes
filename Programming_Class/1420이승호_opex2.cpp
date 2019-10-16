#include <iostream>
#include <string>
using namespace std;

class Time {
	int hour, min, sec;
public:
	Time(int h, int m, int s) : hour{ h }, min{ m }, sec{ s }{}
	void print() {
		cout << hour << ":" << min << ":" << sec << "\n";
	}
	Time& operator++();
	Time operator++(int);
};

Time& Time::operator++() {
	this->min++;
	return *this;
}

Time Time::operator++(int) {
	Time temp(hour, min, sec);
	min++;
	return temp;
}

int main() {
	Time t1(3, 10, 10);
	t1.print();
	t1++;
	t1.print();
	t1++;
	t1.print();
}