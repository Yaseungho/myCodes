#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

	int sum = 0, z = 0, zz = 0;
	string num, sum2;
	cin >> num;
	reverse(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++) {
		if (!((i + 1) % 3) || i + 1 == num.size()) {
			if (num[i] == '1') {
				sum += pow(2, z);
			}
			sum2.push_back(sum + 48);
			z = -1;
			sum = 0;
		}
		else {
			if (num[i] == '1') sum += pow(2, z);
		}
		z += 1;
	}
	reverse(sum2.begin(), sum2.end());
	cout << sum2;
}