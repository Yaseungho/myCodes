#include <iostream>
using namespace std;

int main() {
	int Inum;
	double Dnum;
	cout << "int형 입력 :";
	cin >> Inum;
	cout << "double형 입력";
	cin >> Dnum;

	cout << oct << Inum << "\n";
	cout << dec << Inum << "\n";
	cout << hex << Inum << "\n";
	
	cout.precision(6);
	cout << Dnum << "\n";

	cout << scientific;
	cout.precision(5);
	cout << Dnum << "\n";

	cout << defaultfloat;
	cout.precision(6);
	cout << Dnum << "\n";
}