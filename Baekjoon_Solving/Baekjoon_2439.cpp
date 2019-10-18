#include <iostream>
int main() {
	int i, j, n;
	std::cin >> n;
	j = n;
	for (; n > 0; n--) {
		for (i = 1; i < n; i++) {
			std::cout << " ";
		}
		for (i = j; i >= n; i--) {
			std::cout << "*";
		} std::cout << "\n";
	}
}