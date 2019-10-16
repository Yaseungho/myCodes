#include <stdio.h>
int a(int n) {
	if (n > 100) return 0;
	printf("%-8d", n);
	a(n + 1);
}
int main() {
	a(1);
	return 0;
}