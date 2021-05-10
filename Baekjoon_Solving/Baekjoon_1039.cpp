#include <bits/stdc++.h>
using namespace std;
string N; 
int K, M;

string Solve() {
	string mx = "-1";
	set<string> vit;
	queue<string> q;
	q.push(N);
	
	while (K--) {
		vit.clear();
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			string now = q.front();
			q.pop();
			for (int j = 0; j < M; j++) {
				for (int k = j + 1; k < M; k++) {
					string next = now;
					char temp = next[j];
					next[j] = next[k];
					next[k] = temp;

					if (next[0] != '0' && vit.find(next) == vit.end()) {
						vit.insert(next);
						q.push(next);
					}
				}
			}
		}
	}
	while (!q.empty()) {
		mx = max(mx, q.front());
		q.pop();
	}
	return mx;
}

int main() {
	cin >> N >> K;
	M = N.length();

	cout << Solve() << "\n";
}