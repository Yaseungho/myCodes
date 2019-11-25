#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;

int histogram(int start, int end) {
	if (end == start) return 0;
	if (end == start + 1) return vec[start];

	int mid = (end + start) / 2;
	int ret = max(histogram(start, mid), histogram(mid, end));

	int wid = 1, hei = vec[mid];
	int left = mid, right = mid;
	while (right - left + 1 < end - start) {
		int Lnum = -1, Rnum = -1;
		if (left > start) Lnum = min(hei, vec[left - 1]);
		if (right + 1 < end) Rnum = min(hei, vec[right + 1]);
		if (Lnum >= Rnum) {
			hei = Lnum;
			left--;
		}
		else {
			hei = Rnum;
			right++;
		}
		wid++;
		ret = max(ret, wid * hei);
	}
	return ret;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
	cout << histogram(0, n);
}