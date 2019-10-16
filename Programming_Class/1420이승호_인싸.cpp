#include <iostream>
using namespace std;
int main() {
	const int Member = 10;
	int arr1[Member], Max = 0, ss = 0;
	for (int i = 0; i < 10; i++) {
		cout << "뺴뺴로 데이에 받은 초콜릿의 개수: ";
		cin >> arr1[i];
	}
	for (int &i : arr1) {
		if (i > arr1[Max]) Max = arr1[ss];
		ss++;
	}
	cout << "가장 많이 받은 사람은 " << Max + 1 << "번입니다. 당신은 인싸군요!!" << endl;
	return 0;
}