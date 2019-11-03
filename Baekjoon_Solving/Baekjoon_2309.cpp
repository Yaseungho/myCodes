#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	vector<int> people;
	int i = 9, j, k, sum = 0;
	while (i--) {
		int num;
		cin >> num;
		people.push_back(num);
	}
	sort(people.begin(), people.end());
	for (i = 0; i < 9; i++) {
		sum += people[i];
	}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (sum - people[i] - people[j] == 100) {
				for (k = 0; k < 9; k++) if (k != i && k != j) cout << people[k] << "\n";
				return 0;
}	}	}	}