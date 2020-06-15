#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
using namespace std;
typedef vector<int> vi;
set<vi> seq;//수열 저장
vector<vi> circuit; //오일러 경로 저장
map< pair<vi,vi>, int > adj;//first수열 -> second수열 로 가는 경로의 수를 map으로 표현
map<vi, int> ind;//들어오는 간선 수
map<vi, int> outd;//나오는 간선 수
int V, E;

void makeGraph(vi vec1, vi vec2) {
	if (adj.find({ vec1,vec2 }) == adj.end()) adj.insert({ {vec1,vec2},1 });
	else adj[{vec1, vec2}]++;
	if (outd.find(vec1) == outd.end()) outd.insert({ vec1, 1 });
	else outd[vec1]++;
	if (outd.find(vec2) == outd.end()) outd.insert({ vec2, 0 });
	if (ind.find(vec2) == ind.end()) ind.insert({ vec2, 1 });
	else ind[vec2]++;
	if (ind.find(vec1) == ind.end()) ind.insert({ vec1, 0 });
	if (seq.find(vec1) == seq.end()) seq.insert(vec1);
	if (seq.find(vec2) == seq.end()) seq.insert(vec2);
}

void getEulerCircuit(const vi& here) {
	for (set<vi>::iterator it = seq.begin(); it != seq.end(); it++) {
		if (adj.find({ here, * it }) != adj.end()) {
			while (adj[{here, * it}] > 0) {
				adj[{here, * it}]--;
				getEulerCircuit(*it);
			}
		}
	}
	circuit.push_back(here);
}

void solve() {
	for (set<vi>::iterator it = seq.begin(); it != seq.end(); it++) {
		if (ind[*it] + 1 == outd[*it]) {
			getEulerCircuit(*it);
			reverse(circuit.begin(), circuit.end());
			return;
		}
	}
	for (set<vi>::iterator it = seq.begin(); it != seq.end(); it++) {
		if (outd[*it]) {
			getEulerCircuit(*it);
			reverse(circuit.begin(), circuit.end());
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	V = N - M + 1;
	for (int i = 0; i < V; i++) {
		vi vec1, vec2;
		for (int i = 0; i < M; i++) {
			int temp;
			cin >> temp;
			if (i != M - 1) vec1.push_back(temp);
			if (i != 0) vec2.push_back(temp);
		}
		makeGraph(vec1, vec2);
	}		
	solve();
	for (int i = 0; i < circuit.size() - 1; i++) {
		cout << circuit[i][0] << " ";
	}
	for (int i = 0; i < circuit[circuit.size() - 1].size(); i++) {
		cout << circuit[circuit.size() - 1][i] << " ";
	} cout << "\n";
}