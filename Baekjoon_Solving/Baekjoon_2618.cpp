#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define F first
#define S second
using namespace std;
int N, W;
int DP[1001][1002][3];
//DP[a][b][c] : 현제 해결해야 하는 사건이 a이고 저번 사건을 c번 경찰차가 해결했으며 c번이 아닌 경찰차는 최근에 사건b를 해결했을 때 남은 사건을 해결하기 위한 최소 거리
int choices[1001][1002][3];//각 부분 문제에서 최적해를 위한 선택을 저장해놓는다
vector<pair<int, int>> vec;

int solve(int ind1, int ind2, int who) {
	if (ind1 == W + 1) return 0;
	if (DP[ind1][ind2][who] != -1) return DP[ind1][ind2][who];
	pair<int, int> loc[2] = { {1,1}, {N,N} };
	int ind3_1 = 0;//1번 경찰차가 최근에 해결한 사건번호
	int ind3_2 = 0;//2번 경찰차가 최근에 해결한 사건번호
	if (who != 0) {
		loc[who - 1] = vec[ind1 - 1];//who번 경찰차가 저번 사건을 해결했기 때문에 who번 경찰차는 저번 사건의 발생지에 있다.

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