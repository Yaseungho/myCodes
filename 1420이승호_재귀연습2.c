#include <stdio.h>
int a2(int n);
int a1(int n) {
	if (n >= 11) return;
	if (n) printf("\n");
	a2(n);
	a1(n + 1);
}
int a2(int n) {
	printf("*");
	if (!n) return;
	else a2(n - 1);
}
int main() {
	a1(0);
	return 0;
}