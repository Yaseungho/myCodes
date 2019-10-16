#include <stdio.h>
int a(int n, char c) {
	if (!n) return;
	printf("%c", c);
	a(n - 1, c);
}
int main() {
	int n;
	char c;
	scanf("%d %c", &n, &c);
	a(n,c);
	return 0;
}