#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int DP[101][101];

string W, S;

int match(int s, int w) {
	if (DP[s][w] != -1) return DP[s][w];
	if ((S[s] == W[w] || W[w] == '?') && w < W.size() && s < S.size())
		return DP[s][w] = match(s + 1, w + 1);
	if (W.size() == w) return DP[s][w] = (S.size() == s);
	if (W[w] == '*') {
		if (match(s, w + 1) || (s < S.size() && match(s + 1, w))) return DP[s][w] = 1;
	}
	return DP[s][w] = 0;
}

int main() {
	vector<string> result;
	int n;
	cin >> W >> n;
	while (n--) {
		memset(DP, -1, sizeof(DP));
		cin >> S;
		if (match(0, 0)) result.push_back(S);
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	return 0;
}