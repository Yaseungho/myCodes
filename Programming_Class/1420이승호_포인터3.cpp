#include <iostream>

using namespace std;
 
class Time {
public:
	int hour, min, sec;
	Time() :hour{ 0 }, min{ 0 }, sec{ 0 }{}
	Time(int h, int m, int s) : hour{ h }, min{ m }, sec{ s }{}
	void print() {
		cout << "Time ��ü: " << hour << ":" << min << ":" << sec << endl;
	}
};

void Compare(Time t1, Time t2) {
	if (t1.hour == t2.hour && t1.min == t2.min && t1.sec == t2.sec) cout << "�ð��� ��ġ�մϴ�.\n";
	else cout << "�ð��� ��ġ���� �ʽ��ϴ�.\n";
}

void Compare(int h1, int m1, int s1, int h2, int m2, int s2) {
	if (h1 == h2 && m1 == m2 && s1 == s2) cout << "�ð��� ��ġ�մϴ�.\n";
	else cout << "�ð��� ��ġ���� �ʽ��ϴ�.\n";
}

int main() {
	int h, m, s;
	unique_ptr<Time[]> ptr(new Time[2]);
	cout << "1. �� ��? : "; cin >> h;
	cout << "1. �� ��? : "; cin >> m;
	cout << "1. �� ��? : "; cin >> s;
	ptr[0] = Time(h, m, s);
	cout << "2. �� ��? : "; cin >> h;
	cout << "2. �� ��? : "; cin >> m;
	cout << "2. �� ��? : "; cin >> s;
	ptr[1] = Time(h, m, s);
	ptr[0].print();
	ptr[1].print();
	Compare(ptr[0], ptr[1]);
	Compare(ptr[0].hour, ptr[0].min, ptr[0].sec, ptr[1].hour, ptr[1].min, ptr[1].sec);
	return 0;
}