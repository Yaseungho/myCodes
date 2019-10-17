#include <iostream>
using namespace std;

class Myclass {
private:
	int first, second;
public:
	Myclass(int _first, int _second) : first(_first), second(_second) {}
	Myclass& operator++() { // 전위 증가 (연산 진행 후 피연산자의 메모리를 참조하는 lvalue 반환)
		first += 1; //연산을 진행한다.
		second += 1;

		return *this; //연산이 진행된 피연산자의 메모리를 참조하여(lvalue)를 반환한다.
	}
	const Myclass operator++(int) { // 후위 증가 (rvalue)
		Myclass temp(first, second); //연산 전에 temp에 피연산자의 연산 전 값을 저장해놓는다.

		first += 1; //연산을 진행한다.
		second += 1;

		return temp;//temp에 저장해놓았던 연산 전 값(rvalue)를 반환한다.
	}
	Myclass& operator--() { // 전위 감소 (연산 진행 후 피연산자의 메모리를 참조하는 lvalue 반환)
		first -= 1; //연산을 진행한다
		second -= 1;

		return *this; //연산이 진행된 피연산자의 메모리를 참조하여(lvalue)를 반환한다.
	}
	const Myclass operator--(int) { // 후위 감소 (연산 진행 후 연산 전 값인 rvalue를 리턴함.)
		Myclass temp(first, second); //연산 전에 temp에 피연산자의 연산 전 값을 저장해놓는다

		first -= 1; //연산을 진행한다
		second -= 1;

		return temp; //temp에 저장해놓았던 연산 전 값(rvalue)를 반환한다.
	}
	void print() {
		cout << "first : " << this->first << "\nsecond : " << this->second << "\n";
	}
};

int main() {
	Myclass AngGimoCci(1, 2); //앙기모찌
	++(++AngGimoCci);
	AngGimoCci.print();
	--(--(--AngGimoCci));
	AngGimoCci.print();
	return 0;
}