#include <iostream>
#include <string>
using namespace std;

class SMS {

private:
	string sender;
	string receiver;
	string text;
public:
	SMS() {
		sender = "010-1234-5679";
		receiver = "010-1234-5678";
		text = "네, 문제 없네요.";
	}
	SMS(string s, string r = 0, string t = 0) : sender{ s }, receiver{ r }, text{ t }
	{
	}
	void print() {
		cout << "발신자: " << sender << " ";
		cout << "수신자: " << receiver << " ";
		cout << "내용: " << text << "\n";
	}
};

int main() {
	SMS a1{ "010-1234-5678","010-1234-5679","c++ 공부는 잘되가나요?" };
	SMS a2;

	a1.print();
	a2.print();
}
