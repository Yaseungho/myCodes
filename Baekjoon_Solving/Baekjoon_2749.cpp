#include <iostream>
using namespace std;

int fibo[1500000];

int main() {
	long long n;
	cin >> n;
	fibo[1] = 1;
	for (int i = 2; i < 1500000; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= 1000000;
	}
	cout << fibo[n % 1500000];
	return 0;
}