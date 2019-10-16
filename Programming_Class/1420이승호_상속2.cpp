#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
	string name;
	string adress;
	string tell;
public:
	Person() : name{ "" }, adress{ "" }, tell{ "" }{}
	Person(string n, string a, string t) : name{ n }, adress{ a }, tell{ t }{}
	void print() {
		cout << "�̸�: " << name << "\n�ּ�: " << adress << "\n��ȭ��ȣ: " << tell << "\n";
	}
};

class Costomer : public Person {
private:
	int id;
	int mileage;
public:
	Costomer(string n, string a, string t, int i, int m) : Person(n, a, t), id{ i }, mileage{ m }{}
	void print() {
		cout << "�̸�: " << name << "\n�ּ�: " << adress << "\n��ȭ��ȣ: " << tell << "\n���̵�: " << id << "\n���ϸ���: " << mileage << "\n";
	}
};

int main() {
	Costomer c1("��ö��", "����� ���α�", "010-1111-2222", 1, 1000);
	c1.print();
	return 0;
}