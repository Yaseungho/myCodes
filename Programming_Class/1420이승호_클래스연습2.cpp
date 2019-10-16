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
		title = "지오스톰";
		director = "딘 데블린";
		rating = 8.34;
	}
	Movie(string n, string c = 0, double s = 0) : title{ n }, director{ c }, rating{ s }
	{
	}
	void print() {
		cout << "영화 제목: " << title << "\n";
		cout << "영화 감독: " << director << "\n";
		cout << "영화 평점: " << rating << "\n";
	}
};

int main() {
	Movie a1{ "타이타닉","제임스 카메론",9.5 };
	Movie a2;

	a1.print();
	a2.print();
}
