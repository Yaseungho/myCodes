#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c;
	c.resize(a.size() + b.size() + 1);
	for (int i = 0; i < a.size(); i++) 
		for (int j = 0; j < b.size(); j++) 
			c[i + j] += a[i] * b[j];
	return c;
}

void add(vector<int>& a, const vector<int>& b, int k) {
	a.resize(max(a.size(), b.size() + k));
	for (int i = 0; i < b.size(); i++) a[i + k] += b[i];
}

void sub(vector<int>& a, const vector<int>& b) {
	a.resize(max(a.size(), b.size() + 1));
	for (int i = 0; i < b.size(); i++) a[i] -= b[i];
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();
	if (an > bn) return karatsuba(b, a);
	if (bn == 0) return vector<int>();
	if (an <= 50) return multiply(a, b);
	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	add(a0, a1, 0);
	add(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	sub(z1, z0);
	sub(z1, z2);
	vector<int> ret;
	add(ret, z0, 0);
	add(ret, z1, half);
	add(ret, z2, half + half);
	return ret;
}

vector<int> fromString(const string& a) {
	vector<int> ret;
	for (int i = 0; i < a.size(); i++) {
		ret.push_back(a[i] - '0');
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int result = 0;
		string Mambers, Fans;
		cin >> Mambers >> Fans;
		int a = Mambers.size();
		int b = Fans.size();
		vector<int> A(a);
		vector<int> B(b);
		for (int i = 0; i < a; i++) A[i] = (Mambers[i] == 'M');
		for (int i = 0; i < b; i++) B[b - i - 1] = (Fans[i] == 'M');
		vector<int> C = karatsuba(A, B);
		for (int i = a - 1; i < b; i++) if (!C[i]) result++;
		cout << result << "\n";
	}
	return 0;
}