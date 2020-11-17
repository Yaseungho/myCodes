#include <bits/stdc++.h>
using namespace std;
int DP[102];//DP[n] = ���� n��° ������ü���� ������� �� ���� ���� �׾� ���� �� �ִ� �ִ� ����
int choices[102];//������ ������ ����
int n;
class Cuboid {
public:
	int Wid, Hei, Wei;//�ʺ�, ����, ����
	int num; //������ȣ
	Cuboid(int _W, int _H, int _W2, int _n) {
		Wid = _W;
		Hei = _H;
		Wei = _W2;
		num = _n;
	}
};
bool compare(const Cuboid& c1, const Cuboid& c2) {
	return c1.Wei > c2.Wei;
}
vector<Cuboid> vec;

int solve(int now) {
	if (DP[now] != -1) return DP[now];
	int ret = vec[now].Hei, choice = -1;
	for (int i = now; i < n; i++) {
		if (vec[now].Wid > vec[i].Wid) {
			if (ret < vec[now].Hei + solve(i)) {
				ret = vec[now].Hei + solve(i);
				choice = i;
			}
		}
	}
	choices[now] = choice;
	return DP[now] = ret;
}

void print(int now) {
	vector<int> res;
	int cnt = 0;
	while (choices[now] != -1) {
		cnt++;
		res.push_back(vec[now].num);
		now = choices[now];
	}
	cnt++;
	res.push_back(vec[now].num);
	cout << cnt << "\n";
	reverse(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) cout << res[i] << "\n";
}

int main() {
	memset(DP, -1, sizeof(DP));
	cin >> n;
	for (int i = 0; i < n; i++) {
		int W, H, W2;
		cin >> W >> H >> W2;
		vec.push_back(Cuboid(W, H, W2, i + 1));
	}
	sort(vec.begin(), vec.end(), compare);
	int res = 0;
	int start = -1;
	for (int i = 0; i < n; i++) {
		if (res < solve(i)) {
			res = solve(i);
			start = i;
		}
	}
	print(start);
}