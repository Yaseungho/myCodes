#include <iostream>
#include <string>
using namespace std;

class Book {
public:
	string title;
	int price;
	Book() : title{ "0" }, price{ 0 }{}
	Book(string t, int p) : title{ t }, price{ p }{}
	void print() {
		cout << "���� ����: " << title << " ����: " << price << "\n";
	}
};

int main() {
	Book Books[5] = {
		Book("���� ��������", 18000),
		Book("���μ��� �ѱ��� �����", 10800),
		Book("������ ����", 12150),
		Book("90����� �´�", 12600),
		Book("���� ���� ����", 14850)
	};

	for (Book& b : Books) {
		b.print();
	}
	return 0;
}