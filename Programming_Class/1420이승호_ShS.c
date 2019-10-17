#include <stdio.h>
#define OPER < //오름차순

void IntervalSort(int* arr, int begin, int end, int interval) {
	int i, j, temp;
	for (i = begin + interval; i <= end; i += interval) {
		temp = arr[i];
		for (j = i - interval; j >= begin; j -= interval)
			if (temp OPER arr[j]) arr[j + interval] = arr[j];
			else break;
		arr[j + interval] = temp;
	}
}

void ShellSort(int* arr, int n) {
	int i,j, interval = n;
	printf("\n<<<<<<<<<< 셸 정렬 수행 >>>>>>>>>>\n\n");
	while (interval > 1) {
		interval /= 2;
		for (i = 0; i < interval; i++) {
			IntervalSort(arr, i - 1, n - 1, interval);
		}
		printf("interval = %d >> ", interval);
		for (j = 0; j < n; j++) printf("%d ", arr[j]);
		printf("\n");
	}
}

int main() {
	int *arr, i, n;
	printf("정렬할 배열의 크기를 입력하시오. \n");
	scanf_s("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	printf("정렬할 배열의 원소를 입력하시오. \n");
	for (i = 0; i < n; i++) scanf_s("%d", &arr[i]);
	ShellSort(arr, n);
	return 0;
}