#include <iostream>
#include <string>
using namespace std;
int main() {
	string a = { "0" };
	cin >> a;
	for (int i = 1; i <= a.size(); i++) {
		cout << a[i - 1];
		if (!(i % 10)) {
			cout << "\n";
		}
	}return 0;
}