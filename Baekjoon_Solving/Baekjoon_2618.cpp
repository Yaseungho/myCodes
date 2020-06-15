#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define F first
#define S second
using namespace std;
int N, W;
int DP[1001][1002][3];
//DP[a][b][c] : ���� �ذ��ؾ� �ϴ� ����� a�̰� ���� ����� c�� �������� �ذ������� c���� �ƴ� �������� �ֱٿ� ���b�� �ذ����� �� ���� ����� �ذ��ϱ� ���� �ּ� �Ÿ�
int choices[1001][1002][3];//�� �κ� �������� �����ظ� ���� ������ �����س��´�
vector<pair<int, int>> vec;

int solve(int ind1, int ind2, int who) {
	if (ind1 == W + 1) return 0;
	if (DP[ind1][ind2][who] != -1) return DP[ind1][ind2][who];
	pair<int, int> loc[2] = { {1,1}, {N,N} };
	int ind3_1 = 0;//1�� �������� �ֱٿ� �ذ��� ��ǹ�ȣ
	int ind3_2 = 0;//2�� �������� �ֱٿ� �ذ��� ��ǹ�ȣ
	if (who != 0) {
		loc[who - 1] = vec[ind1 - 1];//who�� �������� ���� ����� �ذ��߱� ������ who�� �������� ���� ����� �߻����� �ִ�.

		if(who == 1) ind3_1 = ind1 - 1;
		else ind3_2 = ind1 - 1;

		if (ind2 != 0) {
			if (who == 1) {
				ind3_2 = ind2;
				loc[1] = vec[ind2];
			}
			else {
				ind3_1 = ind2;
				loc[0] = vec[ind2];
			}
		}
	}
	int one = abs(vec[ind1].F - loc[0].F) + abs(vec[ind1].S - loc[0].S) + solve(ind1 + 1, ind3_2, 1);
	int two = abs(vec[ind1].F - loc[1].F) + abs(vec[ind1].S - loc[1].S) + solve(ind1 + 1, ind3_1, 2);
	if (one <= two) {
		choices[ind1][ind2][who] = 1;
		return DP[ind1][ind2][who] = one;
	}
	else {
		choices[ind1][ind2][who] = 2;
		return DP[ind1][ind2][who] = two;
	}
}

void printAnswer(int ind1, int ind2, int who){
	if (ind1 == W + 1) return;
	int choice = choices[ind1][ind2][who];
	int ind3_1 = 0;
	int ind3_2 = 0;
	if (who != 0) {
		if (who == 1) ind3_1 = ind1 - 1;
		else ind3_2 = ind1 - 1;
		if (ind2 != 0) {
			if (who == 1) ind3_2 = ind2;
			else ind3_1 = ind2;
		}
	}
	cout << choice << "\n";
	if (choice == 1) {
		printAnswer(ind1 + 1, ind3_2, 1);
	}
	else {
		printAnswer(ind1 + 1, ind3_1, 2);
	}
}

int main() {
	vec.push_back({ 0,0 });
	memset(DP, -1, sizeof(DP));
	cin >> N >> W;
	for (int i = 0; i < W; i++) {
		int x, y;
		cin >> x >> y;
		vec.push_back({ x,y });
	}
	cout << solve(1, 0, 0) << "\n";

	printAnswer(1, 0, 0);
}