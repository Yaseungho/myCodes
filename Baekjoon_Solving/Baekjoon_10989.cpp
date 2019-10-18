#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);

	int N, arr[10001] = { 0 };
	std::cin >> N;

	while (N--) {
		int num;
		std::cin >> num;
		arr[num]++;
	}
	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			std::cout << i << '\n';
		}
	}
	return 0;
}