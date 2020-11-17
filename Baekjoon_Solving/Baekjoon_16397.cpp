#include <bits/stdc++.h>
using namespace std;
bool visited[100000], cleared = false;
int N, T, G, cnt = -1;
queue<int> q;

int main() {
	cin >> N >> T >> G;
	q.push(N);
	visited[N] = true;
	while (!q.empty()) {
		cnt++;
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int now = q.front();
			q.pop();
			if (now == G) {
				while (!q.empty()) q.pop();
				cleared = true;
				break;
			}
			int A = now + 1, B = now * 2, temp = 1;
			for (; B >= temp; temp *= 10) {} B -= (temp / 10);
			if (A <= 99999 && !visited[A]) {
				q.push(A);
				visited[A] = true;
			}
			if (now * 2 <= 99999 && !visited[B]) {
				q.push(B);
				visited[B] = true;
			}
		}
	}
	if (cleared && cnt <= T) cout << cnt << "\n";
	else cout << "ANG\n";
}