#include <stdio.h>
#define SIZE 8

void SelectionSort(int* arr) {
	int i, j, temp;
	printf("������ ���� : ");			//���� �� ���� ���
	for (i = 0; i < SIZE; i++) printf("%d ", arr[i]);
	printf("\n\n<<<<<<<<<< ���� ���� ���� >>>>>>>>>>\n\n");

	for (i = 0; i < SIZE - 1; i++) {

		int* min = &(arr[i]);		//min Ž���ϱ�
		for (j = i + 1; j < SIZE; j++) {
			if (*min > arr[j]) min = &(arr[j]);
		}

		temp = *min;  		//�� ��ȯ
		*min = arr[i];
		arr[i] = temp;

		printf("%d�ܰ� :  ", i+1);	 //�� �ܰ� ���
		for (j = 0; j < SIZE; j++) printf("%d ", arr[j]);
		printf("\n");

	}
}

int main() {
	int arr[SIZE] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	SelectionSort(arr);
	return  0;
}