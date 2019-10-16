#include <stdio.h>
int main() {
	int a, b;
	printf("가로길이 입력: ");
	scanf("%d",&a);
	printf("세로길이 입력: ");
	scanf("%d",&b);
	printf("가로와 세로 길이가 %d, %d인 사각형의 넓이는 %d이다.\n밑변과 높이가 %d, %d인 삼각형의 넓이는 %d이다.\n", a, b, a*b, a, b, a*b / 2);
	return 0;
}