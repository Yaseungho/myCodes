#include <stdio.h>
#define OPER < //��������
int main() {
	int *arr, temp, i, j, n;
	printf("������ �迭�� ũ�⸦ �Է��Ͻÿ�. \n");
	scanf_s("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	printf("������ �迭�� ���Ҹ� �Է��Ͻÿ�. \n");
	for (i = 0; i < n; i++) scanf_s("%d", &arr[i]);

	for (i = 1; i < n; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0; j--) 
			if (temp OPER arr[j]) arr[j + 1] = arr[j];
			else break;
		arr[j + 1] = temp;
	}

	printf("���� ��� : ");
	for (i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
	return 0;
}