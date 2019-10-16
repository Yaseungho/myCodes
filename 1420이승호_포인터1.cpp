#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

class Circle {
public:
	int x, y, r;
	Circle() : x{ 0 }, y{ 0 }, r{ 0 }{}
	Circle(int x, int y, int r) : x{ x }, y{ y }, r{ r }{}
	void Draw() {
		int r2 = r / 2;
		HDC hdc = GetWindowDC(GetForegroundWindow());
		Ellipse(hdc, x - r2, y - r2, x + r2, y + r2);
	}
};

int main() {
	srand(time(NULL));
	int n = 0;
	cin >> n;
	unique_ptr<Circle[]> ptr(new Circle[n]);
	for (int i = 0; i < n; i++) {
		ptr[i] = Circle(rand()%1000, rand()%500, rand()%150);
	}
	for (int i = 0; i < n; i++) {
		ptr[i]->Draw();
	}
	return 0;
}
