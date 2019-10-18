#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::vector<std::pair<int, int>>vec;
	int N;
	std::cin >> N;

	while (N--) {
		int a, b;
		std::cin >> a >> b;
		vec.push_back(std::make_pair(a, b));
	}

	std::sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i].first << ' ' << vec[i].second << '\n';
	}
}