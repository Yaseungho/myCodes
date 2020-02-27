#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

string a, b;
int DP[1001][1001]; //DP[N][M] : 1��° ���忡�� N��°�ܾ�, 2��° ���忡�� M��° �ܾ���� ����� ���¿��� ���� �κм��� ����

int func(int ind1, int ind2) {
	if (ind1 == a.size() || ind2 == b.size()) return 0;
	if (DP[ind1][ind2] != -1) return DP[ind1][ind2];
	int ret = 0;
	if (a[ind1] == b[ind2]) ret = 1 + func(ind1 + 1, ind2 + 1);
	else ret = max(func(ind1 + 1, ind2), func(ind1, ind2 + 1));
	return DP[ind1][ind2] = ret;
}

int main() {
	memset(DP, -1, sizeof(DP));
	cin >> a >> b;
	cout << func(0, 0);
}