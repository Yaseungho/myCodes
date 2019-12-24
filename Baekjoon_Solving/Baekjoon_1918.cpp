#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<char> arr;
	string str;
	cin >> str;

	for (int i = 0; i < (int)str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			cout << str[i];
		}
		else if (str[i] == '(') {
			arr.push(str[i]);
		}
		else if (str[i] == ')') {
			while (arr.top() != '(') {
				cout << arr.top();
				arr.pop();
			}
			arr.pop();
		}
		else {
			if (arr.empty() || arr.top() == '(' || ((str[i] == '*' || str[i] == '/') && (arr.top() == '+' || arr.top() == '-'))) {
				arr.push(str[i]);
			}
			else {
				while (!arr.empty() && arr.top() != '(' && !((str[i] == '*' || str[i] == '/') && (arr.top() == '+' || arr.top() == '-'))) {
					cout << arr.top();
					arr.pop();
				}
				arr.push(str[i]);
			}
		}
	}
	while (!arr.empty()) {
		cout << arr.top();
		arr.pop();
	}
}