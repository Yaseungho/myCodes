#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int find(int key) {
	if (key == vec[key]) return key;
	else return vec[key] = find(vec[key]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, num1, num2;
	bool oper; 
	cin >> N >> M;
	for (int i = 0; i <= N; i++) vec.push_back(i);
	while (M--) {
		cin >> oper >> num1 >> num2;
		if (oper) {
			num1 = find(num1);
			num2 = find(num2);
			if (num1 == num2) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			num1 = find(num1);
			num2 = find(num2);
			if (num1 > num2) vec[num1] = num2;
			else vec[num2] = num1;
		}
	}
}