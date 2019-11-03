#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, max = 0, cnt = 0, i, j;
	vector<int> crane;
	vector<int> box;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		crane.push_back(num);
	}
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		box.push_back(num);
	}
	sort(box.begin(), box.end(), greater<int>());
	sort(crane.begin(), crane.end(), greater<int>());
	if (box[0] > crane[0]) {
		cout << "-1";
		return 0;
	}
	while (!box.empty()) {
		for (i = 0; i < crane.size(); i++) {
			for (j = 0; j < box.size(); j++) {
				if (box[j] <= crane[i]) {
					box.erase(box.begin() + j);
					break;
				}
			}
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}