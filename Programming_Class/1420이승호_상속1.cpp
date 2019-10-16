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
		cout << "����:" << name << "\n�������:" << birthYear << "\n";
	}
};

class Student : public Person {
private:
	string university;
public:
	Student(string n, int b, string u) : Person(n, b), university{ u }{}
	void print() {
		cout << "����:" << name << "\n�������:" << birthYear << "\n���б�:"<<university;
	}
};

int main() {
	Student s1("ȫ�浿", 2019, "�ѱ��ִϴ��б�");
	s1.print();
	return 0;
}