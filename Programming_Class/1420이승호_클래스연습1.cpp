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
		name = "������� 350";
		capacity = 400;
		speed = 1000;
	}
	Airplane(string n, int c = 0, int s = 0) : name{ n }, capacity{ c }, speed{ s }
	{
	}
	void print() {
		cout << "������� �̸�: " << name << "\n";
		cout << "������� �뷮: " << capacity << "\n";
		cout << "������� �ӵ�: " << speed << " Km/h\n";
	}
};

int main() {
	Airplane a1{"���� 787",900,300};
	Airplane a2;

	a1.print();
	a2.print();
}
