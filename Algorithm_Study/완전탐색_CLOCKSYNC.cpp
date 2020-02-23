#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result = 99999999;
const vector<vector<int> > Switches ({
	vector<int>({ 0, 1, 2 }),
	vector<int>({ 3, 7, 9, 11 }),
	vector<int>({ 4, 10, 14, 15 }),
	vector<int>({ 0, 4, 5, 6, 7 }),
	vector<int>({ 6, 7, 8, 10, 12 }),
	vector<int>({ 0, 2, 14, 15 }),
	vector<int>({ 3, 14, 15 }),
	vector<int>({ 4, 5, 7, 14, 15 }),
	vector<int>({ 1, 2, 3, 4, 5 }),
	vector<int>({ 3, 4, 5, 9, 13 })
});

int SetClock(const vector<int>& vec, vector<int> Clocks) {
	int ret = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < Switches[i].size(); j++) {
			Clocks[Switches[i][j]] += vec[i] * 3;
			Clocks[Switches[i][j]] %= 12;
		}
	}
	for (int i = 0; i < 16; i++) if (Clocks[i]) return 99999999;
	for (int i = 0; i < 10; i++) ret += vec[i];
	return ret;
}

void SetSwitches(vector<int>& vec, int toPick, vector<int>& Clocks) {
	if (toPick == 0) {
		result = min(result, SetClock(vec, Clocks));
		return;
	}
	for (int i = 0; i < 4; i++) {
		vec.push_back(i);
		SetSwitches(vec, toPick - 1, Clocks);
		vec.pop_back();
	}
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		result = 99999999;
		vector<int> Clocks;
		int temp;
		for (int i = 0; i < 16; i++) {
			cin >> temp;
			Clocks.push_back(temp);
		}
		vector<int> vec;
		SetSwitches(vec, 10, Clocks);
		cout << (result == 99999999 ? -1 : result) << "\n";
	}
}