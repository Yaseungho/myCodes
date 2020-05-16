#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr1;
vector<int> arr2;

int gcd(int n1, int n2) {
	if (n1 > n2) swap(n1, n2);
	if (n1 == 0) return n2;
	return gcd(n2 % n1, n1);
}

int solve(int start, int next) {
	if (next == arr2.size()) return start;
	return solve(gcd(start, arr2[next]), next + 1);
}

int main() {
	int n, result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr1.push_back(temp);
	}
	sort(arr1.begin(), arr1.end());
	for (int i = 1; i < n; i++) {
		arr2.push_back(arr1[i] - arr1[i - 1]);
	}
	sort(arr2.begin(), arr2.end());
	int temp2 = solve(arr2[0], 1);
	for (int i = 0; i < arr2.size(); i++) {
		result += arr2[i] / temp2 - 1;
	}
	cout << result << "\n";
}