#include <iostream>
using namespace std;
class Counter {
private:
	int value;
public:
	Counter(int v = 10) : value{ v } {};
	~Counter() {}
	int getValue() const { return value; }
	void setValue(int x) { value = x; }

	Counter& operator++();
	const Counter operator++(int);
	Counter& operator--();
	const Counter operator--(int);
};

Counter& Counter::operator++() {
	this->value++;
	return *this;
}

const Counter Counter::operator++(int) {
	const Counter c1(value);
	value++;
	return c1;
}

Counter& Counter::operator--() {
	this->value--;
	return *this;
}

const Counter Counter::operator--(int) {
	const Counter c1(value);
	value--;
	return c1;
}


int main() {
	Counter c;
	cout << "카운터의 값: " << c.getValue() << "\n";
	--c;
	cout << "카운터의 값: " << c.getValue() << "\n";
	++c;
	cout << "카운터의 값: " << c.getValue() << "\n";
	return 0;
}