#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

int jump(int num) {
	int temp = 1, ret = 0;
	while (num) {
		num -= temp;
		if (temp * 2 > num) {
			temp = 1;
		}
		else temp *= 2;
		ret++;
	}
	return ret;
}

int jumpmax(int start, int end) {
	if (end == start) return jump(start);
	if (end - start == 1) return max(jump(start), jump(end));
	int i;
	for (i = 0; i < 31; i++) {
		if (arr[i] > end) {
			break;
		}
	}
	if (arr[i - 1] >= start) {
		if (arr[i - 2] >= start) {
			return max(i - 2 + jumpmax(0, arr[i - 1] - arr[i - 2] - 1), i - 1 + jumpmax(0, end - arr[i - 1]));
		}
		else if (arr[i - 1] == start) {
			return i - 1 + jumpmax(0, end - arr[i - 1]);
		}
		else {
			return max(i - 2 + jumpmax(start - arr[i - 2], arr[i - 1] - arr[i - 2] - 1), i - 1 + jumpmax(0, end - arr[i - 1]));
		}
	}
	else {
		return i - 1 + jumpmax(start - arr[i - 1], end - arr[i - 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> vec;
	int temp = 1;
	for (int i = 0; i < 31; i++) {
		arr.push_back(temp - 1);
		temp *= 2;
	}
	int a = 0;
	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		vec.push_back(jumpmax(x, y));
	}
	for (int& v : vec) cout << v << "\n";
}