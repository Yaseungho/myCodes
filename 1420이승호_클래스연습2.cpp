#include <iostream>
#include <string>
using namespace std;

class Movie {

private:
	string title;
	string director;
	double rating;
public:
	Movie() {
		title = "��������";
		director = "�� ����";
		rating = 8.34;
	}
	Movie(string n, string c = 0, double s = 0) : title{ n }, director{ c }, rating{ s }
	{
	}
	void print() {
		cout << "��ȭ ����: " << title << "\n";
		cout << "��ȭ ����: " << director << "\n";
		cout << "��ȭ ����: " << rating << "\n";
	}
};

int main() {
	Movie a1{ "Ÿ��Ÿ��","���ӽ� ī�޷�",9.5 };
	Movie a2;

	a1.print();
	a2.print();
}
