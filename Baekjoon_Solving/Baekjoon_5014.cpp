#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int F, S, G, U, D;
bool visited[1000001] = { false };

int BFS() {
	queue<pair<int,int>> q;
	q.push({ S, 0 });
	visited[S] = true;
	while (!q.empty()) {
		for (int i = 0; i < q.size(); i++) {
			pair<int,int> now = q.front();
			q.pop();
			pair<int, int> down = { now.first - D, now.second + 1 };
			pair<int, int> up = { now.first + U, now.second + 1 };
			if (down.first >= 1 && !visited[down.first]) {
				if (down.first == G) return down.second;
				visited[down.first] = true;
				q.push(down);
			}
			if (up.first <= F && !visited[up.first]) {
				if (up.first == G) return up.second;
				visited[up.first] = true;
				q.push(up);
			}
		}
	}
	return -1;
}

int main() {
	cin >> F >> S >> G >> U >> D;
	if (S == G) cout << "0\n";
	else {
		int result = BFS();
		if (result == -1) cout << "use the stairs\n";
		else cout << result << "\n";
	}
}