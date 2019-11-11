#include <iostream>
using namespace std;

long long func(long long A, long long B, long long C) {
	if (B == 1) return A % C;
	int temp = func(A, B / 2, C);
	if (B & 1) return (temp % C) * ((temp * A) % C) % C;
	else return (temp % C) * (temp % C) % C;
}

int main() {
	long long A, B, C;
	cin >> A >> B >> C;
	cout << func(A, B, C);
	return 0;
}