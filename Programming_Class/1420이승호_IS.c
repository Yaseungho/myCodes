#include <stdio.h>
#define OPER < //오름차순
int main() {
	int *arr, temp, i, j, n;
	printf("정렬할 배열의 크기를 입력하시오. \n");
	scanf_s("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	printf("정렬할 배열의 원소를 입력하시오. \n");
	for (i = 0; i < n; i++) scanf_s("%d", &arr[i]);

	for (i = 1; i < n; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0; j--) 
			if (temp OPER arr[j]) arr[j + 1] = arr[j];
			else break;
		arr[j + 1] = temp;
	}

	printf("정렬 결과 : ");
	for (i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
	return 0;
}