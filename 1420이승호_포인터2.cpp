#include <iostream>

using namespace std;

class Circle {
public:
	double radius;
	double D;
	Circle() : radius{ 0 }, D{ 0 }{}
	Circle(double r) : radius{ r }, D{ radius * radius * 3.14 }{}
};

int main() {
	int n, r, count = 0;
	cout << "������ ���� ���� : ";
	cin >> n;
	unique_ptr<Circle[]> ptr(new Circle[n]);
	for (int i = 0; i < n; i++) {
		cout << "�� " << i + 1 << "�� ������ >> ";
		cin >> r;
		ptr[i] = Circle(r);
	}
	for (int i = 0; i < n; i++) {
		if (ptr[i].D > 100) count++;
	}
	cout << "������ 100���� ū ���� " << count << "�� �Դϴ�" << endl;
	return 0;
}