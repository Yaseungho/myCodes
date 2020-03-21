#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
int V, E;

void DFS(int here) {
	visited[here] = true;
	for (int i = 0; i < graph[here].size(); i++) {
		if (!visited[graph[here][i]]) DFS(graph[here][i]);
	}
}

int cntComponent() {
	int ret = 0;
	visited = vector<bool>(E + 1, false);
	for (int i = 1; i <= E; i++) {
		if (!visited[i]) {
			DFS(i);
			ret++;
		}
	}
	return ret;
}

int main() {
	cin >> E >> V;
	graph.resize(E + 1);
	for (int i = 0; i < V; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cout << cntComponent() << "\n";
}