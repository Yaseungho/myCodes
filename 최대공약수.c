#include <stdio.h>
int main() {
	int a, b, c;
	printf("ù��° ���� �Է�: "); scanf("%d", &a);
	printf("�ι�° ���� �Է�: "); scanf("%d", &b);
	for (a; a%b != 0;) {
		if (a > b) { c = a;  a = b;  b = c % b; }
		if (a < b) { c = b;  b = a;  a = c % a; }
	} printf("�ִ����� : %d\n", b);
	return 0;
}