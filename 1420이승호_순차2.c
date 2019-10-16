#include <stdio.h>
int main() {
	int a;
	printf("m단위의 길이 입력: ");
	scanf("%d", &a);
	printf("%dkm %dm\n", a / 1000, a % 1000);
}