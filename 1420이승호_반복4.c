#include <stdio.h>
int main() {
	int a, i;
	for (i = 1; i < 11; i++) {
		printf("%dÀÇ ¾à¼ö: ", i);
		for (a = 1; a < 11; a++) {
			if (i%a == 0) printf("%d ", a);
		}
		printf("\n");
	}
	return 0;
}