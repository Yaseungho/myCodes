#include <stdio.h>
int main() {
	int a, i;
	scanf("%d", &a);
	i = a;
	for (a; a != 0;) {
		scanf("%d", &a);
		if (a > i) i = a;
	}
	printf("���� ū ��: %d\n", i);
	return 0;
}