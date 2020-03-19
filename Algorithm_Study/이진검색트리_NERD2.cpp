#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> survivers;

bool isDead(int p, int q) {
	map<int, int>::iterator it = survivers.lower_bound(p);
	if (it == survivers.end()) return false;
	return q < it->second;
}

void kill(int p, int q) {
	map<int, int>::iterator it = survivers.lower_bound(p);
	if (it == survivers.begin()) return;
	--it;
	while (1) {
		if (it->second > q) break;
		if (it == survivers.begin()) {
			survivers.erase(it);
			break;
		}
		else {
			map<int, int>::iterator temp = it;
			temp--;
			survivers.erase(it);
			it = temp;
		}
	}
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		survivers.clear();
		int N, p, q, result = 0;
		cin >> N;
		while (N--) {
			cin >> p >> q;
			if (!isDead(p, q)) {
				kill(p, q);
				survivers[p] = q;
			}
			result += survivers.size();
		}
		cout << result << "\n";
	}
}