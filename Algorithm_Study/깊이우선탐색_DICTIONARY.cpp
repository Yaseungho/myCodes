#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int Dictionary[26][26];
vector<int> visited;
vector<int> sorted;

void makeGraph(const vector<string>& words) {
	for (int j = 1; j < words.size(); j++) {
		int i = j - 1, len = min(words[i].size(), words[j].size());
		for (int k = 0; k < len; k++)
			if (words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				Dictionary[a][b] = 1;
				break;
			}
	}
}

void DFS(const int& here) {
	visited[here] = 1;
	for (int i = 0; i < 26; i++) if (!visited[i] && Dictionary[here][i]) DFS(i);
	sorted.push_back(here);
}

void DFSall() {
	visited = vector<int>(26, 0);
	for (int i = 0; i < 26; i++) if (!visited[i]) DFS(i);
}

int main() {
	int c;
	cin >> c;
	while (c--) {

		bool result = true;
		vector<string> strarr;
		memset(Dictionary, 0, sizeof(Dictionary));
		sorted.clear();
		int n;
		cin >> n;
		while (n--) {
			string temp;
			cin >> temp;
			strarr.push_back(temp);
		}
		makeGraph(strarr);
		DFSall();
		reverse(sorted.begin(), sorted.end());
		for (int i = 0; i < 26; i++) {
			for (int j = i + 1; j < 26; j++) {
				if (Dictionary[sorted[j]][sorted[i]]) {
					cout << "INVALID HYPOTHESIS\n";
					result = false;
					break;
				}
			}
			if (!result) break;
		}
		if (result) {
			for (auto& v : sorted) cout << (char)(v + 97);
			cout << "\n";
		}
	}
}