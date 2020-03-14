#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

bool match(const string& str) {
	stack<char> stack;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '{' || str[i] == '[' || str[i] == '(') stack.push(str[i]);//���°�ȣ��� ���ÿ� �ִ´�
		else {
			if (stack.empty()) return false; //������ ������� ����
			if ((stack.top() == '(' && str[i] == ')') || 
				(stack.top() == '{' && str[i] == '}') || 
				(stack.top() == '[' && str[i] == ']')) stack.pop();
			else return false;
		}//�ݴ°�ȣ��� ������ top�� ���ؼ� �ٸ���� ����
	}
	if (stack.empty()) return true;//������ ����ִٸ� ��
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