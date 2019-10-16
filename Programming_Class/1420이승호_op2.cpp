#include <iostream>
#include <string>
using namespace std;

class Time {
	int hour, min, sec;
public:
	Time(int h, int m, int s) : hour{ h }, min{ m }, sec{ s }{}
	bool operator==(const Time& t2);
	bool operator!=(const Time& t2);
};

bool Time::operator==(const Time& t2) {
	return this->hour == t2.hour && this->min == t2.min && this->sec == t2.sec;
}

bool Time::operator!=(const Time& t2) {
	return this->hour != t2.hour || this->min != t2.min || this->sec != t2.sec;
}

int main() {
	Time t1(1, 2, 3), t2(1, 2, 3);
	cout.setf(cout.boolalpha);
	cout << (t1 == t2) << "\n";
	cout << (t1 != t2) << "\n";
	return 0;
}