#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> M;
	vector<int> vec(M);
	for (int i = 0; i < M; i++) cin >> vec[i];
	sort(arr.begin(), arr.end());
	for (int i = 0; i < M; i++) {
		int key = vec[i];
		vector<int>::iterator it = lower_bound(arr.begin(), arr.end(), key);
		if (it != arr.end() && *(it) == key) cout << "1\n";
		else cout << "0\n";
	}
}