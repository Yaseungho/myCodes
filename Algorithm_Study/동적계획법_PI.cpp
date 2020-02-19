#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

string PI;
int DP[10002];

int difficult(string temp) {
	if (temp == string(temp.size(), temp[0])) return 1;
	bool progressive = true;
	for (int i = 0; i < temp.size() - 1; i++) 
		if (temp[i + 1] - temp[i] != temp[1] - temp[0]) 
			progressive = false;
	if (progressive && abs(temp[1] - temp[0]) == 1) return 2;
	bool alternating = true;
	for (int i = 0; i < temp.size(); i++) if (temp[i] != temp[i % 2]) alternating = false;
	if (alternating) return 4;
	if (progressive) return 5;
	return 10;
}

int func(int num) {
	if (num == PI.size()) return 0;
	if (DP[num] != -1) return DP[num];
	int ret = 99999999;
	for (int i = 3; i <= 5; i++) {
		if(num + i <= PI.size())
		ret = min(ret, difficult(PI.substr(num, i)) + func(num + i));
	}
	return DP[num] = ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		memset(DP, -1, sizeof(DP));
		cin >> PI;
		cout << func(0) << "\n";
	}
}