#include <stdio.h>
#define SIZE 8

void SelectionSort(int* arr) {
	int i, j, temp;
	printf("정렬할 원소 : ");			//정렬 전 원소 출력
	for (i = 0; i < SIZE; i++) printf("%d ", arr[i]);
	printf("\n\n<<<<<<<<<< 선택 정렬 수행 >>>>>>>>>>\n\n");

	for (i = 0; i < SIZE - 1; i++) {

		int* min = &(arr[i]);		//min 탐색하기
		for (j = i + 1; j < SIZE; j++) {
			if (*min > arr[j]) min = &(arr[j]);
		}

		temp = *min;  		//값 교환
		*min = arr[i];
		arr[i] = temp;

		printf("%d단계 :  ", i+1);	 //각 단계 출력
		for (j = 0; j < SIZE; j++) printf("%d ", arr[j]);
		printf("\n");

	}
}

int main() {
	int arr[SIZE] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	SelectionSort(arr);
	return  0;
}