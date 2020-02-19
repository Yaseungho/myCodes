#include <iostream>
using namespace std;

int main() {
	long long A, B, V, start = 0, end = 1000000001, mid, temp, result;
	cin >> A >> B >> V;
	while (end - start > 1) {
		mid = (start + end) / 2;
		temp = (mid - 1) * (A - B) + A;
		if (temp >= V) {
			result = mid;
			end = mid;
		}
		else start = mid;
	}

	cout << result;
	return 0;
}