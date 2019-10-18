#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
int main() {
	int N;
	scanf("%d", &N);

	std::vector<int> vec;

	while (N--) {
		int num;
		scanf("%d", &num);
		vec.push_back(num);
	}

	std::sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << '\n';
	}
	return 0;
}