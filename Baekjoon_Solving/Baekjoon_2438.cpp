#include <iostream>
int main() {
	int i, j, n;
	std::cin >> n;
	j = n;
	for (; n > 0; n--) {
		for (i = j; i >= n; i--) {
			std::cout << "*";
		} std::cout << "\n";
	}
}