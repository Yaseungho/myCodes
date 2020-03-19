#include <iostream>
#include <vector>
using namespace std;

void func(const vector<int>& pre, const vector<int>& in) {
	if (pre.empty()) return;
	int Root = pre[0], Size = pre.size();
	int L = 0, R = 0;
	for (int i = 0; i < in.size(); i++) {
		if (in[i] == Root) {
			L = i;
			R = Size - 1 - i;
		}
	}
	func(vector<int>(pre.begin() + 1, pre.begin() + L + 1), 
		 vector<int>(in.begin(),in.begin() + L));//¿ÞÂÊ
	func(vector<int>(pre.begin() + L + 1, pre.end()),
		 vector<int>(in.begin() + L + 1, in.end()));//¿À¸¥ÂÊ
	cout << Root << " ";
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int N, temp;
		cin >> N;
		vector<int> pre;
		vector<int> in;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			pre.push_back(temp);
		}
		for (int i = 0; i < N; i++) {
			cin >> temp;
			in.push_back(temp);
		}
		func(pre, in);
		cout << "\n";
	}
}