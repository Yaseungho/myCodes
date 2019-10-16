#include <stdio.h>
int main() {
	int a;
	printf("수 입력: ");
	scanf("%d", &a);
	if (a % 5 == 0 && a % 7 == 0) printf("5의 배수이며 7의 배수이다.\n");
	else if (a % 5 == 0) printf("5의 배수이다.\n");
	else if (a % 7 == 0) printf("7의 배수이다.\n");
	else printf("5의 배수도 7의 배수도 아니다.\n");
	return 0;
}