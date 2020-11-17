#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, sum = 0, cnt = 1, cntMax = 1, mode_first, mode_second = -9999;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		sum += vec[i];
	}
	sort(vec.begin(), vec.end(), greater<int>());
	mode_first = vec[0];
	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i] == vec[i + 1]) {
			cnt++;
			if (cnt > cntMax) {
				mode_second = -9999;
				cntMax = cnt;
				mode_first = vec[i];
			}
			else if (cnt == cntMax) {
				mode_second = mode_first;
				mode_first = vec[i];
			}
		}
		else {
			if (cntMax == 1) {
				mode_second = mode_first;
				mode_first = vec[i + 1];
			}
			cnt = 1;
		}
	}
	cout << round((double)sum / (double)n) << "\n"; //»ê¼úÆò±Õ
	cout << vec[n / 2] << "\n"; //Áß¾Ó°ª
	cout <<  (mode_second == -9999 ? mode_first : mode_second) << "\n"; //ÃÖºó°ª
	cout << vec[0] - vec[n - 1] << "\n"; //¹üÀ§
}