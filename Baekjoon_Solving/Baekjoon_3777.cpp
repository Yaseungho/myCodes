#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> DP[1001];

void normalize(vector<int>& n) {
	n.push_back(0);
	for (int i = 0; i < n.size() - 1; i++) {
		if (n[i] < 0) {
			int borrow = (abs(n[i]) + 9) / 10;
			n[i + 1] -= borrow;
			n[i] += borrow * 10;
		}
		else {
			n[i + 1] += n[i] / 10;
			n[i] %= 10;
		}
	}
	while (n.size() > 1 && n.back() == 0) n.pop_back();
}

vector<int> multiply1(const vector<int>& a, int n) {
	vector<int> c;
	c.resize(a.size() + 1);
	for (int i = 0; i < a.size(); i++)
		c[i] += a[i] * n;
	c[0]--;
	normalize(c);
	return c;
}

vector<int> multiply2(const vector<int>& a, int n) {
	vector<int> c;
	c.resize(a.size() + 1);
	for (int i = 0; i < a.size(); i++)
			c[i] += a[i] * n;
	c[0]++;
	normalize(c);
	return c;
}

vector<int> func(int num) {
	if (num == 1) {
		vector<int> t1 = { 0 };
		return t1;
	}
	if (num == 2) {
		vector<int> t2 = { 1 };
		return t2;
	}
	vector<int> t3 = { -1 };
	if (DP[num] != t3) return DP[num];
	if (num % 2) {
		return DP[num] = multiply1(func(num - 1), 2);
	}
	else {
		return DP[num] = multiply2(func(num - 1), 2);
	}
}

int main() {
	fill(DP, DP + 1001, vector<int>{ -1 });
	int n;
	while (cin >> n) {
		vector<int> result = func(n);
		for (int i = (int)result.size() - 1; i >= 0; i--) {
			cout << result[i];
		}
		cout << "\n";
	}
	return 0;
}