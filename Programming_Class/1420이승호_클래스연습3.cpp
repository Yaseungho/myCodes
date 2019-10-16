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
		text = "��, ���� ���׿�.";
	}
	SMS(string s, string r = 0, string t = 0) : sender{ s }, receiver{ r }, text{ t }
	{
	}
	void print() {
		cout << "�߽���: " << sender << " ";
		cout << "������: " << receiver << " ";
		cout << "����: " << text << "\n";
	}
};

int main() {
	SMS a1{ "010-1234-5678","010-1234-5679","c++ ���δ� �ߵǰ�����?" };
	SMS a2;

	a1.print();
	a2.print();
}
