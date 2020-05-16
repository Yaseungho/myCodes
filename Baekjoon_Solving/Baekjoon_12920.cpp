#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int DP[10001][10001];//DP[n][m] : n번째 물건부터 고려해야 하며 현재 무게가 m일때 최대 가치
int N, M;

struct Item {
	int weight;
	int value;
	Item(int w, int v) : weight{ w }, value{ v } {}
};

vector<Item> vec;

int func(int n, int weight) {
	if (n == vec.size()) return 0;//기저 사례 : 모두 고려했을 시 0리턴
	if (DP[n][weight] != -1) return DP[n][weight];
	int ret = func(n + 1, weight);
	if (weight + vec[n].weight <= M) ret = max(ret, vec[n].value + func(n + 1, weight + vec[n].weight));
	return DP[n][weight] = ret;
}

int main() {
	memset(DP, -1, sizeof(DP));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int V, C, K;
		cin >> V >> C >> K;
		for (int i = 1; K > 0; i *= 2) {
			int temp = min(i, K);
			vec.push_back(Item(V * temp, C * temp));
			K -= temp;
		}
	}
	cout << func(0, 0) << "\n";
}