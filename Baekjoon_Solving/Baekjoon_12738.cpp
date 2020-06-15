#include <iostream>
using namespace std;
int LIS[1000001] = { 0 };

int main() {
	int N, len = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (i == 0 || LIS[len - 1] < temp) {
			LIS[len++] = temp;
		}
		else {
			int start = 0, end = len - 1;
			while (end != start) {
				int mid = (end + start) / 2;
				if (LIS[mid] >= temp) end = mid;
				else start = mid + 1;
			}
			LIS[end] = temp;
		}
	}
	cout << len << "\n";
}