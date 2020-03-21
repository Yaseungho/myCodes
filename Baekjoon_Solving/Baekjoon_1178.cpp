#include <iostream>
#include <vector>
using namespace std;
bool Graph[1001][1001] = { false };
vector<bool> visited = { false };
vector<vector<int>> sliced;
int V, E;

int addvoltex(vector<int> vec) {
	int cnt = 0;
	for (int i = 0; i < vec.size(); i++) {
		int temp = 0;
		for (int j = 0; j < vec.size(); j++) {
			if (Graph[vec[i]][vec[j]]) temp++;
		}
		if (temp % 2) cnt++;
	}
	if (cnt == 0) return 0;
	else if (cnt % 2) return cnt / 2;
	else return cnt / 2 - 1;
}

void DFS(int here, vector<int>& ret) {
	visited[here] = true;
	for (int i = 1; i <= V; i++) {
		if (Graph[here][i] && !visited[i]) {
			DFS(i, ret);
		}
	}
	ret.push_back(here);
}

int Solve() {
	int cntComponent = -1;
	int result = 0;
	visited = vector<bool>(V + 1, false);
	for (int i = 1; i <= V; i++) {
		if (!visited[i]) {
			vector<int> temp;
			DFS(i, temp);
			if (temp.size() > 1) {
				sliced.push_back(temp);
				cntComponent++;
			}
		}
	}
	for (int i = 0; i < sliced.size(); i++) {
		int temp = addvoltex(sliced[i]);
		result += temp;
	}
	return result + cntComponent;
}

int main() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		Graph[a][b] = true;
		Graph[b][a] = true;
	}
	cout << Solve() << "\n";
}

