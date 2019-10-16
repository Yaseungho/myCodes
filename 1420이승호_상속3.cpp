#include <iostream>
#include <Windows.h>
using namespace std;

class Square {
protected:
	int x, y;
	int width;
	int height;
public:
	Square() :x{ 0 }, y{ 0 }{}
	Square(int x, int y, int w, int h) : x{ x }, y{ y }, width{ w }, height{ h }{}
};

class ColorSquare : public Square {
private:
	int red;
	int green;
	int blue;
public:
	ColorSquare(int x, int y, int w, int h, int r, int g, int b) : Square(x, y, w, h), red{ r }, green{ g }, blue{ b }{}
	void draw() {
		HDC hdc = GetWindowDC(GetForegroundWindow());
		SelectObject(hdc, GetStockObject(DC_BRUSH));
		SetDCBrushColor(hdc, RGB(red, green, blue));
		Rectangle(hdc, x, y, x + width, y + height);
	}
};

int main() {
	ColorSquare s1(100, 50, 150, 200, 255, 0, 0);
	s1.draw();
	ColorSquare s2(200, 300, 300, 500, 0, 255, 0);
	s2.draw();
	ColorSquare s3(50, 300, 500, 200, 0, 0, 255);
	s3.draw();
	return 0;
}