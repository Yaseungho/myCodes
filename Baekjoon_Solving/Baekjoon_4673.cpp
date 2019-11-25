#include <iostream>
using namespace std;

bool arr[10001] = { false };

int func(int i) {
	int ret = i;
	while (i) {
		ret += i % 10;
		i /= 10;
	}
	return ret;
}

int main() {
	for (int i = 1; i <= 10000; i++) {
		int temp = i;
		while (temp <= 10000) {
			temp = func(temp);
			arr[temp] = true;
		}
	}
	for (int i = 1; i <= 10000; i++) {
		if (!arr[i]) cout << i << "\n";
	}
	return 0;
}