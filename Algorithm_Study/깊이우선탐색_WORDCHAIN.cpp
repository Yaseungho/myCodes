#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
vector<string> words[26][26];
int graph[26][26];
int indegree[26];
int outdegree[26];
vector<int> result;
int N;

void func(int here) {
	for (int i = 0; i < 26; i++) {
		while (graph[here][i] > 0) {
			graph[here][i]--;
			func(i);
		}
	}
	result.push_back(here);
}

void printWords() {
	if (result.size() != N + 1) cout << "IMPOSSIBLE\n";
	else {
		reverse(result.begin(), result.end());
		for (int i = 1; i < result.size(); i++) {
			cout << words[result[i - 1]][result[i]].back() << " ";
			words[result[i - 1]][result[i]].pop_back();
		} cout << "\n";
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 26; i++) {
			indegree[i] = 0;
			outdegree[i] = 0;
		}
		int cnt = 0, start, one = 0, two = 0;
		result.clear();
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++) words[i][j].clear();
		memset(graph, 0, sizeof(graph));
		string temp;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			graph[temp[0] - 97][temp.back() - 97]++;
			words[temp[0] - 97][temp.back() - 97].push_back(temp);
			outdegree[temp[0] - 97]++;
			indegree[temp.back() - 97]++;
		}
		for (int i = 0; i < 26; i++) {
			if (indegree[i] != outdegree[i]) {
				if (indegree[i] + 1 == outdegree[i]) {
					one++;
					start = i;
				}
				else if (indegree[i] == outdegree[i] + 1) two++;
				else one = 99999999;
			}
		}
		if (one == 0 && two == 0) {
			for (int i = 0; i < 26; i++) {
				if (outdegree[i] > 0) {
					func(i);
					printWords();
					break;
				}
			}
		}
		else if (one == 1 && two == 1) {
			func(start);
			printWords();
		}
		else cout << "IMPOSSIBLE\n";
	}
}