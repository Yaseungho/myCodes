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
	Book Books[5] = {
		Book("반일 종족주의", 18000),
		Book("설민석의 한국사 대모험", 10800),
		Book("여행의 이유", 12150),
		Book("90년생이 온다", 12600),
		Book("유럽 도시 기행", 14850)
	};

	for (Book& b : Books) {
		b.print();
	}
	return 0;
}