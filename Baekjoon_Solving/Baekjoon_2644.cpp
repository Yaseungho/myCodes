#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> graph;
int V, E, one, two;
int result = -1;

void BFS() {
	vector<bool> visited(V, false);
	queue<int> q;
	q.push(one - 1);
	visited[one - 1] = true;

	int depth = 1;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();
			for (int next : graph[now]) {
				if (!visited[next]) {
					if (next == two - 1) result = depth;
					visited[next] = true;
					q.push(next);
				}
			}
		}
		depth++;
	}
}

int main() {
	cin >> V >> one >> two >> E;
	graph.resize(V);
	for (int i = 0; i < E; i++) {
		int x, y;
		cin >> x >> y;
		graph[x - 1].push_back(y - 1);
		graph[y - 1].push_back(x - 1);
	}
	BFS();
	cout << result << "\n";
}