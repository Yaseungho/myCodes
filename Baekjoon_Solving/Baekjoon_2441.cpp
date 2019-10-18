#include <stdio.h>
int main() {
	int n, n2, n3;
	scanf("%d", &n);
	n2 = n;
	for (; n > 0; n--) {
		for (n3 = n; n3 < n2; n3++) printf(" ");
		for (n3 = 0; n3 < n; n3++) printf("*");
		printf("\n");
	}return 0;
}