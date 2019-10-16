#include <stdio.h>
int main() {
	int a = 0, i;
	for (i =0; i < 100; i+=3) a += i;
	printf("3의 배수의 합: %d\n", a);
	return 0;
}