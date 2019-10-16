#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
	int birthYear;
	string name;
public:
	Person() : name{ "" }, birthYear{ 0 }{}
	Person(string n, int b) : name{ n }, birthYear{ b }{}
	void print() {
		cout << "성명:" << name << "\n출생연도:" << birthYear << "\n";
	}
};

class Student : public Person {
private:
	string university;
public:
	Student(string n, int b, string u) : Person(n, b), university{ u }{}
	void print() {
		cout << "성명:" << name << "\n출생연도:" << birthYear << "\n대학교:"<<university;
	}
};

int main() {
	Student s1("홍길동", 2019, "한국애니대학교");
	s1.print();
	return 0;
}