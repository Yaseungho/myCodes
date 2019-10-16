#include <stdio.h>
int main() {
	int a, b, i = 0;
	printf("피라미드 높이 입력 : "); scanf("%d", &a); b = a;
	for (; a > 0; a--) {
		for (i = a; i > 1; i--) {
			printf(" ");
		} 
		for (i = b << 1; i >= a << 1; i--) {
			printf("@");
		} printf("\n");
	}
	return 0;
}