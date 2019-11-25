#include <iostream>
using namespace std;

int main() {
	unsigned long long int n;
	cin >> n;
	if ((
		(n - 1) % 5) == 1
		||
		((n - 1) % 5) == 4)
		cout << "CY";
	else cout << "SK";
	return 0;
}