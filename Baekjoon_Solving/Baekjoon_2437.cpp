#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, sum = 0;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; i++) {
		if (sum + 1 < vec[i]) {
			cout << sum + 1 << "\n";
			return 0;
		}
		sum += vec[i];
	}
	cout << sum + 1 << "\n";
}