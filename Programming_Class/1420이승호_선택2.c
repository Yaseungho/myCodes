#include <stdio.h>
int main() {
	int a;
	printf("�� �Է�: ");
	scanf("%d", &a);
	if (a % 5 == 0 && a % 7 == 0) printf("5�� ����̸� 7�� ����̴�.\n");
	else if (a % 5 == 0) printf("5�� ����̴�.\n");
	else if (a % 7 == 0) printf("7�� ����̴�.\n");
	else printf("5�� ����� 7�� ����� �ƴϴ�.\n");
	return 0;
}