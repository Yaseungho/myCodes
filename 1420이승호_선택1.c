#include <stdio.h>
int main() {
	int a, b, c;
	printf("�� �� �Է�: ");
	scanf("%d %d %d", &a, &b, &c);
	if (a < b)	a = b;
	if (a > c)	c = a;
	printf("���� ū ��: %d\n", c);
	return 0;
}