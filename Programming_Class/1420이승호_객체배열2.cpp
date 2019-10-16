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
		cout << "도서 제목: " << title << " 가격: " << price << "\n";
	}
};

int main() {
	Book Books[10];

	for (Book& b : Books) {
		cin >> b.title;
		cin >> b.price;
	}
	for (Book& b : Books) {
		b.print();
	}
	return 0;
}