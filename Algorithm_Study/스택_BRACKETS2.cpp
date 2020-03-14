#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

bool match(const string& str) {
	stack<char> stack;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '{' || str[i] == '[' || str[i] == '(') stack.push(str[i]);//여는괄호라면 스택에 넣는다
		else {
			if (stack.empty()) return false; //스택이 비었으면 거짓
			if ((stack.top() == '(' && str[i] == ')') || 
				(stack.top() == '{' && str[i] == '}') || 
				(stack.top() == '[' && str[i] == ']')) stack.pop();
			else return false;
		}//닫는괄호라면 스택의 top과 비교해서 다를경우 거짓
	}
	if (stack.empty()) return true;//스택이 비어있다면 참
	return false;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		string str;
		cin >> str;
		cout << (match(str) ? "YES\n" : "NO\n");
	}
	return 0;
}