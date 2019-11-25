#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> vec;

long long getmax(int start, int end) {
	if (end == start) return 0;
	if (end == start + 1) return vec[start] * vec[start];

	int mid = (end + start) / 2;
	long long ret = max(getmax(start, mid), getmax(mid, end));

	long long value = vec[mid];
	int left = mid, right = mid;
	long long sum = value;
	while (right - left + 1 < end - start) {
		int Lnum = -1, Rnum = -1;
		if (left > start) Lnum = min(value, vec[left - 1]);
		if (right + 1 < end) Rnum = min(value, vec[right + 1]);
		if (Lnum >= Rnum) {
			value = Lnum;
			left--;
			sum += vec[left];
		}
		else {
			value = Rnum;
			right++;
			sum += vec[right];
		}
		ret = max(ret, sum * value);
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
	cout << getmax(0, n);
}