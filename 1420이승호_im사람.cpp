#include <iostream>
#include <string>
using namespace std;
class Person {
public:
	int age;
	int weight;
	int height;
	char bloodtype;
	string gender;
	void walk() {
		cout << "±æÀ» °É¾ú´Ù." << endl;
	}
	void eat() {
		cout << "¹äÀ» ¸Ô¾ú´Ù." << endl;
	}
};