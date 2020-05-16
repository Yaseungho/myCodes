#include <iostream>
#include <vector>
using namespace std;
vector<int> graph;
vector<bool> visited;
vector<bool> finished;
int n, cnt;

void DFS(int here) {
	visited[here] = true;
	int next = graph[here];
	if (!visited[next]) DFS(next);
	else if (!finished[next]) {
		for (int temp = next; temp != here; temp = graph[temp]) cnt++;
		cnt++;
	}
	finished[here] = true;
}

int GetCycles() {
	cnt = 0;
	visited = vector<bool>(n + 1, false);
	finished = vector<bool>(n + 1, false);
	for (int i = 1; i <= n; i++) if (!visited[i]) DFS(i);
	return cnt;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		graph.resize(n + 1);
		for (int i = 1; i <= n; i++) cin >> graph[i];
		cout << n - GetCycles() << "\n";
	}
}