#include <iostream>
int main() {
	int i, n;
	std::cin >> n;
	for (; n > 0; n--) {
		for (i = 0; i < n; i++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
}