#include <stdio.h>
int main() {
	int a, b, c;
	printf("첫번째 숫자 입력: "); scanf("%d", &a);
	printf("두번째 숫자 입력: "); scanf("%d", &b);
	for (a; a%b != 0;) {
		if (a > b) { c = a;  a = b;  b = c % b; }
		if (a < b) { c = b;  b = a;  a = c % a; }
	} printf("최대공약수 : %d\n", b);
	return 0;
}