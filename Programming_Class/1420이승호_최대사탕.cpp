#include <iostream>
using namespace std;
int main() {
	int m = 1000; //철수의 돈
	int c = 300; //사탕의 가격
	cout << "현재 가지고 있는 돈: " << m << endl;
	cout << "캔디의 가격: " << c << endl;
	cout << "최대로 살 수 있는 캔디의 개수: " << m / c << endl;
	cout << "캔디 구입 후 남은 돈 = " << m % c << endl;
}