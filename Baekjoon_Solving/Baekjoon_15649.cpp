#include <iostream>
using namespace std;
int arr[9];
bool visited[9];
int m, n;

void func(int num) {
	if (num == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[num] = i;
			func(num + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	func(0);
	return 0;
}