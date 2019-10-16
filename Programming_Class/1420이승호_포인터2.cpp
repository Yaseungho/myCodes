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
	cout << "생성할 원의 개수 : ";
	cin >> n;
	unique_ptr<Circle[]> ptr(new Circle[n]);
	for (int i = 0; i < n; i++) {
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> r;
		ptr[i] = Circle(r);
	}
	for (int i = 0; i < n; i++) {
		if (ptr[i].D > 100) count++;
	}
	cout << "면적이 100보다 큰 원은 " << count << "개 입니다" << endl;
	return 0;
}