#include <stdio.h>
int arr[41];
int fibonacci(int n) {
	if (n <= 1) return n;
	else if (arr[n]) return arr[n];
	else return arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n == 0) printf("1 0\n");
		else printf("%d %d\n", fibonacci(n - 1), fibonacci(n));
	} return 0;
}