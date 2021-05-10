#include <bits/stdc++.h>
using namespace std;
int A, B;
const char DSLR[4] = { 'D', 'S', 'L', 'R' };

void Solve() {
	pair<int, char> prev[10000];
	vector<bool> vit(10000);
	queue<int> q;
	vector<char> res;
	q.push(A);
	vit[A] = true;
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int now = q.front(), next;
			q.pop();
			if (now == B) {
				while (now != A) {
					res.push_back(prev[now].second);
					now = prev[now].first;
				}
				reverse(res.begin(), res.end());
				for (char ch : res) cout << ch;
				cout << "\n";
				return;
			}
			int nextArr[4] = { 
				(now * 2) % 10000,
				now == 0 ? 9999 : now - 1,
				(now % 1000) * 10 + now / 1000, 
				(now % 10) * 1000 + now / 10 };
			for (int i = 0; i < 4; i++) {
				next = nextArr[i];
				if (!vit[next]) {
					vit[next] = true;
					q.push(next);
					prev[next] = { now, DSLR[i] };
				}
			}
		}
	}
}

int main() {
	int T; cin >> T;
	while (T--) {
		cin >> A >> B;
		Solve();
	}
}