#include <iostream>
using namespace std;

class Charactor {

private:
	int x;
	int y;
	int HP;
public:
	Charactor() {
		x = 0;
		y = 0;
		HP = 100;
	}
	Charactor(int s, int r = 0, int t = 0) : x{ s }, y{ r }, HP{ t }
	{
	}
	void print() {
		cout << "x: " << x << " y: " << y << " HP: " << HP << "\n";
	}
	void sestX() {
		for (int i = 0; i < 9; i++) {
			x += 10;
			print();
		}
	}
};

int main() {
	Charactor a1;

	a1.sestX();
}
