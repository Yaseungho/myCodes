#include <bits/stdc++.h>
using namespace std;
bool Graph[1001][1001] = { false };
int Degree[1001];
vector<bool> visited = { false };
int V, E;

int DFS(int here) {
    visited[here] = true;
    int ret = Degree[here] % 2;
    for (int i = 1; i <= V; i++) {
        if (Graph[here][i] && !visited[i]) ret += DFS(i);
    }
    return ret;
}

int Solve() {
    int ret = -1;
    visited = vector<bool>(V + 1, false);
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            int odd = DFS(i);
            ret += (odd > 1 ? odd / 2 : 1);
        }
    }
    return ret;
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        Graph[a][b] = true;
        Graph[b][a] = true;
        Degree[a]++;
        Degree[b]++;
    }
    cout << Solve() << "\n";
}