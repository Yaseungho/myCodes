#include <stdio.h>
int main() {
	float arr[1000], max = 0.0f, sum = 0.0f;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > max) max = arr[i];
	}
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] / max * 100;
		sum += arr[i];
	} printf("%f\n", sum / n);
	return 0;
}