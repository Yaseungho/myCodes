#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class Circle {
public:
	int x, y, r;
	Circle() : x{ 0 }, y{ 0 }, r{ 0 }{}
	void draw() {
		int r2 = r / 2;
		HDC hdc = GetWindowDC(GetForegroundWindow());
		Ellipse(hdc, x - r2, y - r2, x + r2, y + r2);
	}
};

int main() {
	srand(time(NULL));
	Circle Circles[100];
	for (Circle& c : Circles) {
		char ch = _getch();
		if (ch == 'q') break;
		else if (ch == 'c') {
			c.x = rand() % 1000;
			c.y = rand() % 600;
			c.r = rand() % 150;
			c.draw();
		}
		else continue;
	}
	system("cls");
	return 0;
}