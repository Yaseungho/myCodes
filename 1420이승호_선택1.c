#include <stdio.h>
int main() {
	int a, b, c;
	printf("세 수 입력: ");
	scanf("%d %d %d", &a, &b, &c);
	if (a < b)	a = b;
	if (a > c)	c = a;
	printf("가장 큰 수: %d\n", c);
	return 0;
}