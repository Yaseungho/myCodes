#include <stdio.h>
int main() {
	int a;
	printf("�� ���� �ð� �Է�: ");
	scanf("%d", &a);
	printf("%d�� ", a / 1440);
	a = a % 1440;
	printf("%d�ð� %d��\n", a / 60, a % 60);
	return 0;
}