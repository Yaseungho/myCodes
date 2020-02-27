#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int DP[101][1001];//DP[a][b]현재 남은부피가 b일 때 a번째부터 고른 물건들의 최대 가치 합
int W, N;

class object {
public:
	string name;
	int volume, value;
	object() : name{ " " }, volume{ 0 }, value{ 0 } {}
};

int func(int ind, int capacity, vector<object>& objects) {
	if (ind == N) return 0;
	if (DP[ind][capacity] != -1) return DP[ind][capacity];
	int ret = func(ind + 1, capacity, objects);
	if (capacity - objects[ind].volume >= 0) {
		ret = max(ret, objects[ind].value + func(ind + 1, capacity - objects[ind].volume, objects));
	}
	return DP[ind][capacity] = ret;
}

void func2(int ind, int capacity, vector<string>& names, vector<object>& objects) {
	if (ind == N) return;
	if (func(ind, capacity, objects) == func(ind + 1, capacity, objects)) func2(ind + 1, capacity, names, objects);
	else {
		names.push_back(objects[ind].name);
		func2(ind + 1, capacity - objects[ind].volume, names, objects);
	}
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		memset(DP, -1, sizeof(DP));
		object temp;
		vector<object> objects;
		cin >> N >> W;
		for (int i = 0; i < N; i++) {
			cin >> temp.name >> temp.volume >> temp.value;
			objects.push_back(temp);
		}
		vector<string> names;
		cout << func(0, W, objects) << " ";
		func2(0, W, names, objects);
		cout << names.size() << "\n";
		for (auto& v : names) cout << v << "\n";
	}
}