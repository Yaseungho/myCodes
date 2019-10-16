#include <stdio.h>
int main() {
	int a;
	printf("분 단위 시간 입력: ");
	scanf("%d", &a);
	printf("%d일 ", a / 1440);
	a = a % 1440;
	printf("%d시간 %d분\n", a / 60, a % 60);
	return 0;
}