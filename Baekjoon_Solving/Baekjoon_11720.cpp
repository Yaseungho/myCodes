#include <iostream>
using namespace std;
int main() {
	int a, c = 0;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		int b;
		scanf("%1d", &b);
		c += b;
	}
	printf("%d", c);
}