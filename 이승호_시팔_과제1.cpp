#include <iostream>
using namespace std;

int main() {
	int Inum;
	double Dnum;
	cout << "int�� �Է� :";
	cin >> Inum;
	cout << "double�� �Է�";
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