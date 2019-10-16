#include <iostream>
#define SIZE 10

using namespace std;

class MyArray {
private:
	int a[SIZE];
public:
	MyArray() {
		for (int i = 0; i < SIZE; i++) a[i] = 0;
	}
	int& operator[](int i);
};

int& MyArray::operator[](int i) {
	if (i <= SIZE) return (this->a[i]);
	else {
		cout << "잘못된 인덱스 : ";
		a[i] = 0;
		return (this->a[i]);
	}
}

int main() {
	MyArray A;
	A[3] = 9;
	cout << "A[3]= " << A[3] << "\n";
	cout << "A[16]= " << A[16] << "\n";
	return 0;
}