#include <stdio.h>
int main() {
	int a, b;
	printf("���α��� �Է�: ");
	scanf("%d",&a);
	printf("���α��� �Է�: ");
	scanf("%d",&b);
	printf("���ο� ���� ���̰� %d, %d�� �簢���� ���̴� %d�̴�.\n�غ��� ���̰� %d, %d�� �ﰢ���� ���̴� %d�̴�.\n", a, b, a*b, a, b, a*b / 2);
	return 0;
}