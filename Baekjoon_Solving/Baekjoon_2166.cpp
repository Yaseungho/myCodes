#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef double ld;
typedef pair<ld, ld> pld;
vector<pld> vec;


int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(1);
	ld sum = 0;
	int N;
	cin >> N;
	vec.resize(N);
	for (int i = 0; i < N; i++) cin >> vec[i].x >> vec[i].y;
	vec.push_back(vec[0]);
	for (int i = 0; i < N; i++) {
		sum += vec[i].x * vec[i + 1].y;
		sum -= vec[i].y * vec[i + 1].x;
	}
	sum = abs(sum / 2);
	cout << round(sum * 100) / 100 << "\n";
}