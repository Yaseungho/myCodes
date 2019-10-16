#include <stdio.h>
int main() {
	int a, i;
	scanf("%d", &a);
	i = a;
	for (a; a != 0;) {
		scanf("%d", &a);
		if (a > i) i = a;
	}
	printf("가장 큰 수: %d\n", i);
	return 0;
}