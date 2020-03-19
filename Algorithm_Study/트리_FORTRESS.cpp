#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct castle {
	int x;
	int y;
	int r;
};

vector<castle> vec;

struct node {
	vector<node*> children;
};

bool encloses(int a, int b) {
	return vec[a].r > vec[b].r && pow(vec[a].y - vec[b].y, 2) + pow(vec[a].x - vec[b].x, 2) < pow(vec[a].r - vec[b].r, 2);
}

bool compare(const castle& temp1, const castle& temp2) {
	return temp1.r < temp2.r;
}

bool isChild(int child, int parent) {
	for (int i = child; i < vec.size(); i++) if (encloses(i, child)) return i == parent;
	return false;
}

node* maketree(int root) {
	node* ret = new node();
	for (int i = 0; i < vec.size(); i++) if (isChild(i, root)) ret->children.push_back(maketree(i));
	return ret;
}

int result;

int height(node* root) {
	if (root->children.empty()) return 0;
	vector<int> heights;
	for (int i = 0; i < root->children.size(); i++) heights.push_back(height(root->children[i]));
	sort(heights.begin(), heights.end(), greater<int>());
	if (heights.size() >= 2) result = max(result, 2 + heights[0] + heights[1]);
	return heights[0] + 1;
}

int func(node* root) {
	result = 0;
	int h = height(root);
	return max(h, result);
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		result = 0;
		vec.clear();
		int N;
		cin >> N;
		while (N--) {
			int x, y, r;
			cin >> x >> y >> r;
			vec.push_back({ x,y,r });
		}
		sort(vec.begin(), vec.end(), compare);
		cout << func(maketree(vec.size() - 1)) << "\n";
	}
}