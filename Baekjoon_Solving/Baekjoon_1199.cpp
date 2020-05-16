#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int graph[1001][1001];
vector<bool> visited;
int n;

void bfs(int here) {
	visited[here] = true;
	for (int i = 0; i < n; i++) {
		while (graph[here][i]) {
			graph[here][i]--;
			graph[i][here]--;
			bfs(i);
		}
	}
	cout << here + 1 << " ";
}

void printEuler() {
	visited = vector<bool>(n, false);
	
	for (int i = 0; i < n; i++) {
		if (!visited[i]) bfs(i);
	}
	cout << "\n";
}

int main() {
	cin >> n;
	bool isEuler = true;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			if (graph[i][j]) cnt += graph[i][j];
		}
		if (cnt % 2) isEuler = false;
	}
	if (isEuler) printEuler();
	else cout << "-1\n";
}