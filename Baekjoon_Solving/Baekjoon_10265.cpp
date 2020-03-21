#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int n;
vector<int> graph;
vector<vector<int>> undi_graph;
vector<bool> visited;
vector<bool> visited2;
vector<bool> finished;
vector< pair< int,int > > components;//각 컴포넌트는 학생을 first명부터 second명 태울수 있다
int DP[1002][1002];//DP[n][m] : n명의 학생이 더 탈수있고 m번 컴포넌트 전까지는 고려했을 때 탈 수 있는 승객의 최댓값

void CountCycles(int here, int& cnt) {
	visited[here] = true;
	int next = graph[here];
	if (!visited[next]) CountCycles(next, cnt);
	else if (!finished[next]) {
		for (int temp = next; temp != here; temp = graph[temp]) cnt++;
		cnt++;
	}
	finished[here] = true;
}

void CountComponents(int here, int& cnt) {
	visited2[here] = true;
	for (int i = 0; i < undi_graph[here].size(); i++) if (!visited2[undi_graph[here][i]]) CountComponents(undi_graph[here][i], cnt);
	cnt++;
}

void getComponentsAndCycles() {
	visited = vector<bool>(n + 1, false);	
	finished = vector<bool>(n + 1, false);
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			int cnt1 = 0, cnt2 = 0;
			CountCycles(i, cnt1);
			if (cnt1) {
				visited2 = vector<bool>(n + 1, false);
				CountComponents(i, cnt2);
				components.push_back({ cnt1,cnt2 });
			}
		}
	}
}

int func(int k, int num) {
	if (k < 0) return -99999999;//학생의 수가 초과되어버리면 불가능
	if (num == components.size()) return 0;//모두 고려했다면 0리턴
	if (DP[k][num] != -1) return DP[k][num];
	int ret = func(k, num + 1);//이 컴포넌트를 무시할 경우
	for (int i = components[num].first; i <= components[num].second; i++) {
		ret = max(ret, i + func(k - i, num + 1));//이 컴포넌트에서 탈수있는 모든 학생의 경우중 최댓값 찾기
	}
	return DP[k][num] = ret;
}

int main() {
	memset(DP, -1, sizeof(DP));
	int k;
	cin >> n >> k;
	graph.resize(n + 1);
	undi_graph.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		graph[i] = temp;
		undi_graph[i].push_back(temp);
		undi_graph[temp].push_back(i);
	}
	getComponentsAndCycles();
	cout << func(k, 0) << "\n";
}