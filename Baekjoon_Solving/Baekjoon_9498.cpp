#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (90 <= n) cout << "A\n";
	else if (80 <= n) cout << "B\n";
	else if (70 <= n) cout << "C\n";
	else if (60 <= n) cout << "D\n";
	else cout << "F\n";
}