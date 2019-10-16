#include <stdio.h>
int main() {
	int a, i;
	for (a = 5; a != 0; a--) {
		for (i = a; i != 0; i--) printf("%d ", i);
		printf("\n");
	}
	return 0;
}