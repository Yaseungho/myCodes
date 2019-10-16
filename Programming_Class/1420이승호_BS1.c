#include <stdio.h>
#define SIZE 8

void BubbleSort(int* arr) {
	int i, j, k, temp;
	printf("정렬할 원소 : ");			//정렬 전 원소 출력
	for (i = 0; i < SIZE; i++) printf("%d ", arr[i]);
	printf("\n\n<<<<<<<<<< 버블 정렬 수행 >>>>>>>>>>\n\n");

	for (i = SIZE - 1; i > 0; i--) {
		printf("%d단계 >> \n", SIZE - i + 1);
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			printf("    ");
			for (k = 0; k < SIZE; k++) printf("%d ", arr[k]);
			printf("\n");
		}
	}
}

int main() {
	int arr[SIZE] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	BubbleSort(arr);
	return  0;
}