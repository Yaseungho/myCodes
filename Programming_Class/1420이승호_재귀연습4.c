#include <stdio.h>
int turn(char* Word, int i, int Size) {
	if (i > Size / 2) return;
	char temp = *(Word + i);
	*(Word + i) = *(Word + Size - i);
	*(Word + Size - i) = temp;
	turn(Word, i + 1, Size);
}
int main() {
	char Word[100];
	int Size;
	scanf("%s", Word);
	for (Size = 0; Word[Size] != 0; Size++){}
	turn(Word, 0, Size - 1);
	printf("%s", Word);
	return 0;
}