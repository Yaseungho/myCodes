#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> tree;
vector<char> res1, res2, res3;

void preorder(int now) {
	if (now < 0) return;
	res1.push_back(now);
	preorder(tree[now].first);	
	preorder(tree[now].second);
}

void inorder(int now) {
	if (now < 0) return;
	inorder(tree[now].first);
	res2.push_back(now);
	inorder(tree[now].second);
}

void postorder(int now) {
	if (now < 0) return;
	postorder(tree[now].first);
	postorder(tree[now].second);
	res3.push_back(now);
}

int main() {
	int N;
	char n, r, l;
	cin >> N;
	tree.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> n >> r >> l;
		tree[n - 'A'] = { r - 'A', l - 'A' };
	}
	preorder(0); inorder(0); postorder(0);
	for (int i : res1) cout << (char)(i + 'A');
	cout << "\n";
	for (int i : res2) cout << (char)(i + 'A');
	cout << "\n";
	for (int i : res3) cout << (char)(i + 'A');
	cout << "\n";
}