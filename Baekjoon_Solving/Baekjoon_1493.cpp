#include <iostream>
using namespace std;

int result;
int arr[21] = {0};
bool is = true;

void fillBox(int l, int w, int h) {
	if (l <= 0 || w <= 0 || h <= 0 || !is) return;
	int temp = 2097152;
	for (int i = 20; i >= 0; i--) {
		temp /= 2;
		if (arr[i] != 0 && temp <= l && temp <= w && temp <= h) {
			arr[i]--;
			result++;
			fillBox(l - temp, w, h);
			fillBox(temp, w - temp, h);
			fillBox(temp, temp, h - temp);
			return;
		}
	}
	is = false;
	return;
}//가로세로높이

int main() {
	int l, w, h, N, kind, num;
	cin >> l >> w >> h >> N;
	while (N--) {
		cin >> kind >> num;
		arr[kind] = num;
	}
	fillBox(l, w, h);
	if (is) cout << result;
	else cout << "-1";
	return 0;
}