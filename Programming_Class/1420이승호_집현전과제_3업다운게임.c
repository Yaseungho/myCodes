#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	srand(time(NULL)*20);
	int num = 1 + (rand() % 999), a, b = 0;
	printf("���ٿ� ������ �����մϴ�! 1���� 1000������ �ӿ��� ���� ���纸����!\n");
	while (1) {
		b++;
		printf("�� �Է� : "); scanf("%d", &a);
		if (a == num) { printf("������ϴ�! �Է� Ƚ�� : %d\n", b); break; }
		else if (a < num) printf("��\n");
		else if (a > num) printf("�ٿ�\n");
	}
	return 0;
}