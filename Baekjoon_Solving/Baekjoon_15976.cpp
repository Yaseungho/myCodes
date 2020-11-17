#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;
map<int, int> index;
vector<pair<int, int>> xVal, yVal;//realInd, val
int M, N, a, b;
vector<long long> psum;

int main() {
	vector <pair<int, int>> x, y;
	vector<int> temp;
	int ind, val;
	long long res = 0, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ind >> val;
		temp.push_back(ind);
		x.push_back({ ind, val });
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> ind >> val;
		index[ind] = 0;
		y.push_back({ ind, val });
	}
	cin >> a >> b;
	for (int n : temp) {
		index[n] = 0;
		index[n + b] = 0;
		index[n + a - 1] = 0;
	}
	int maxind = 0;
	for (map<int, int>::iterator it = index.begin(); it != index.end(); it++) (*it).second = maxind++;
	xVal.resize(maxind); yVal.resize(maxind); psum.resize(maxind);
	for (int i = 0; i < N; i++) xVal[index[x[i].first]] = x[i];
	for (int i = 0; i < M; i++) yVal[index[y[i].first]] = y[i];
	for (int i = 0; i < maxind; i++) {
		sum += yVal[i].second;
		psum[i] = sum;
	}
	for (int i = 0; i < maxind; i++) {
		res += (xVal[i].second * (psum[index[xVal[i].first + b]] - psum[index[xVal[i].first + a - 1]]));
	}
	cout << res << "\n";
}