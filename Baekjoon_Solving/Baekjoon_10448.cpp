#include <iostream>
#include <vector>
using namespace std;

int main() {
	int sum = 0, i, j, k, num, T;
	bool is = true;
	vector<int> Tvec;
	for (i = 1; sum < 1000; i++) {
		sum += i;
		Tvec.push_back(sum);
	}
	cin >> T;
	while (T--) {
		cin >> num;
		is = true;
		for (i = 0; i < Tvec.size() && is; i++) {
			for (j = 0; j < Tvec.size() && is; j++) {
				for (k = 0; k < Tvec.size() && is; k++) {
					if (num == Tvec[i] + Tvec[j] + Tvec[k]) {
						is = false;
					}
				}
			}
		}
		if (is) cout << "0\n";
		else cout << "1\n";
	}
	return 0;
}