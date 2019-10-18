#include <string>
#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	int a = 1;
	for (char i = 'a'; i <= 'z'; i++) {
		a = 1;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == i) {
				cout << j << " ";
				a = 0;
				break;
			}
		}
		if (a) cout << "-1 ";
	}
	return 0;
}