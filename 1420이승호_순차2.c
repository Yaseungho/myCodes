#include <stdio.h>
int main() {
	int a;
	printf("m������ ���� �Է�: ");
	scanf("%d", &a);
	printf("%dkm %dm\n", a / 1000, a % 1000);
}