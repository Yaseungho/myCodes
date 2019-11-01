#include <iostream>
using namespace std;

bool isprime(int num) {
	int i = 2, j = num - 1;
	if (num == 1) return 0;
	while (1) { 
		if (i <= j) {
			if (num % i == 0) return 0;
			else i++;
		}
		else return 1;
	}
}

bool getPrime(int num) {
	int ret = 0;
	for (int i = 1; i < num; i++) {
		if (!(num % i) && isprime(i)) {
			ret++;
		}
	}
	if (ret) return (ret % 2 == 0);
	else return 0;
}

int main() {
	int num;
	bool imhyun = false, imyun = false;
	cin >> num;
	int temp = num;
	int sum = 0;
	while (temp > 0) {
		sum += temp % 10;
		temp /= 10;
	}
	if (sum % 2 && (num >= 6 || num == 4)) imyun = true;
	if (num == 2 || num == 4 || getPrime(num)) imhyun = true;

	if (imyun && !imhyun) cout << 1;
	else if (!imyun && imhyun) cout << 2;
	else if (!imyun && !imhyun) cout << 3;
	else if (imyun && imhyun) cout << 4;
	return 0;
}