#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	srand(time(NULL)*20);
	int num = 1 + (rand() % 999), a, b = 0;
	printf("업다운 게임을 시작합니다! 1부터 1000까지의 임외의 수를 맞춰보세요!\n");
	while (1) {
		b++;
		printf("수 입력 : "); scanf("%d", &a);
		if (a == num) { printf("맞췄습니다! 입력 횟수 : %d\n", b); break; }
		else if (a < num) printf("업\n");
		else if (a > num) printf("다운\n");
	}
	return 0;
}