#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> boys;
vector<int> girls;

int DP[1001][1001]; //DP[n][m] : n번째, m번째부터 고려해야 할 때 나머지의 차이의 합의 최솟값

int func(int b, int g) {
	int bnum = boys.size() - b, gnum = girls.size() - g;
	int ret = 0;
	if (!bnum || !gnum) return 0;
	//기저 사례 : 고려해야 할 남자 혹은 고려해야 할 여자가 없을 경우 0리턴
	if (DP[b][g] != -1) return DP[b][g];
	if (bnum > gnum) {
		ret += min(abs(boys[b] - girls[g]) + func(b + 1, g + 1), func(b + 1, g));
	}//고려해야 할 남자가 더 많을 경우
	else if (bnum < gnum) {
		ret += min(abs(boys[b] - girls[g]) + func(b + 1, g + 1), func(b, g + 1));
	}//고려해야 할 여자가 더 많은 경우
	else {
		ret += abs(boys[b] - girls[g]) + func(b + 1, g + 1);
	}//고려해야 할 남자와 고려해야 할 여자가 같은 경우
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
