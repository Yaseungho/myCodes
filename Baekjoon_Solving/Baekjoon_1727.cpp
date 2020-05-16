#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> boys;
vector<int> girls;

int DP[1001][1001]; //DP[n][m] : n��°, m��°���� ����ؾ� �� �� �������� ������ ���� �ּڰ�

int func(int b, int g) {
	int bnum = boys.size() - b, gnum = girls.size() - g;
	int ret = 0;
	if (!bnum || !gnum) return 0;
	//���� ��� : ����ؾ� �� ���� Ȥ�� ����ؾ� �� ���ڰ� ���� ��� 0����
	if (DP[b][g] != -1) return DP[b][g];
	if (bnum > gnum) {
		ret += min(abs(boys[b] - girls[g]) + func(b + 1, g + 1), func(b + 1, g));
	}//����ؾ� �� ���ڰ� �� ���� ���
	else if (bnum < gnum) {
		ret += min(abs(boys[b] - girls[g]) + func(b + 1, g + 1), func(b, g + 1));
	}//����ؾ� �� ���ڰ� �� ���� ���
	else {
		ret += abs(boys[b] - girls[g]) + func(b + 1, g + 1);
	}//����ؾ� �� ���ڿ� ����ؾ� �� ���ڰ� ���� ���
	return DP[b][g] = ret;
}

int main() {
	memset(DP, -1, sizeof(DP));
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		boys.push_back(temp);
	}	
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		girls.push_back(temp);
	}
	sort(boys.begin(), boys.end());
	sort(girls.begin(), girls.end());
	cout << func(0, 0) << "\n";
}
