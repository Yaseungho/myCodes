#include <iostream>
using namespace std;

class Myclass {
private:
	int first, second;
public:
	Myclass(int _first, int _second) : first(_first), second(_second) {}
	Myclass& operator++() { // ���� ���� (���� ���� �� �ǿ������� �޸𸮸� �����ϴ� lvalue ��ȯ)
		first += 1; //������ �����Ѵ�.
		second += 1;

		return *this; //������ ����� �ǿ������� �޸𸮸� �����Ͽ�(lvalue)�� ��ȯ�Ѵ�.
	}
	const Myclass operator++(int) { // ���� ���� (rvalue)
		Myclass temp(first, second); //���� ���� temp�� �ǿ������� ���� �� ���� �����س��´�.

		first += 1; //������ �����Ѵ�.
		second += 1;

		return temp;//temp�� �����س��Ҵ� ���� �� ��(rvalue)�� ��ȯ�Ѵ�.
	}
	Myclass& operator--() { // ���� ���� (���� ���� �� �ǿ������� �޸𸮸� �����ϴ� lvalue ��ȯ)
		first -= 1; //������ �����Ѵ�
		second -= 1;

		return *this; //������ ����� �ǿ������� �޸𸮸� �����Ͽ�(lvalue)�� ��ȯ�Ѵ�.
	}
	const Myclass operator--(int) { // ���� ���� (���� ���� �� ���� �� ���� rvalue�� ������.)
		Myclass temp(first, second); //���� ���� temp�� �ǿ������� ���� �� ���� �����س��´�

		first -= 1; //������ �����Ѵ�
		second -= 1;

		return temp; //temp�� �����س��Ҵ� ���� �� ��(rvalue)�� ��ȯ�Ѵ�.
	}
	void print() {
		cout << "first : " << this->first << "\nsecond : " << this->second << "\n";
	}
};

int main() {
	Myclass AngGimoCci(1, 2); //�ӱ����
	++(++AngGimoCci);
	AngGimoCci.print();
	--(--(--AngGimoCci));
	AngGimoCci.print();
	return 0;
}