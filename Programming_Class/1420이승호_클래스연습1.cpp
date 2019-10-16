#include <iostream>
#include <string>
using namespace std;

class Airplane {

private:
	string name;
	int capacity;
	int speed;
public:
	Airplane() {
		name = "에어버스 350";
		capacity = 400;
		speed = 1000;
	}
	Airplane(string n, int c = 0, int s = 0) : name{ n }, capacity{ c }, speed{ s }
	{
	}
	void print() {
		cout << "비행기의 이름: " << name << "\n";
		cout << "비행기의 용량: " << capacity << "\n";
		cout << "비행기의 속도: " << speed << " Km/h\n";
	}
};

int main() {
	Airplane a1{"보잉 787",900,300};
	Airplane a2;

	a1.print();
	a2.print();
}
