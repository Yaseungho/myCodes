#include <iostream>
using namespace std;
int main() {
	const int Member = 10;
	int arr1[Member], Max = 0, ss = 0;
	for (int i = 0; i < 10; i++) {
		cout << "������ ���̿� ���� ���ݸ��� ����: ";
		cin >> arr1[i];
	}
	for (int &i : arr1) {
		if (i > arr1[Max]) Max = arr1[ss];
		ss++;
	}
	cout << "���� ���� ���� ����� " << Max + 1 << "���Դϴ�. ����� �να���!!" << endl;
	return 0;
}