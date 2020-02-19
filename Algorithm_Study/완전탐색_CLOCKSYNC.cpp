#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result = INT_MAX;

bool Switches[10][16] = {
   //0 1 2 3 4 5 6 7 8 9 101112131415
	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
	{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
	{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
	{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0},
};

int SetClock(vector<int>& vec, vector<int> _Clocks) {
	vector<int> Clocks;
	Clocks.resize(16);
	copy(_Clocks.begin(), _Clocks.end(), Clocks.begin());
	int ret = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 16; j++) {
			if (Switches[i][j] == 1) {
				for (int k = 0; k < vec[i]; k++) {
					if (Clocks[j] == 12) Clocks[j] = 3;
					else Clocks[j] += 3;
				}
			}
		}
	}
	for (int i = 0; i < 16; i++) if (Clocks[i] != 12) return INT_MAX;
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
		result = INT_MAX;
		vector<int> Clocks;
		int temp;
		for (int i = 0; i < 16; i++) {
			cin >> temp;
			Clocks.push_back(temp);
		}
		vector<int> vec;
		SetSwitches(vec, 10, Clocks);
		cout << result << "\n";
	}
}