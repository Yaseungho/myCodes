#include <stdio.h>
int main() {
	int Turn = 0, NumberOfWords = 0, Check = 0, i, i2;
	char P1word[7] = { "" };
	char P2word[7] = { "대머리" };
	int WordList[6][100] = { 0 };
	printf("끝말잇기를 시작합니다!\n입력하는 단어는 3글자 한글이어야 합니다.\n\n");
	printf("시작 단어: 대머리\n\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");
	while (1) {
		if (Turn == 0) {
			printf("플레이어1의 턴 : %c%c : ", P2word[4], P2word[5]); scanf("%s", P1word); Turn = 1;
			for (i = 0; i < NumberOfWords; i++) {
				Check = 0;
				for (i2 = 0; i2 < 6; i2++) {
					if (WordList[i2][i] == P1word[i2]) Check++;
				}
				if (Check != 6) {
					Check = 0;
				}
				else {
					printf("플레이어1이 중복되는 단어를 사용하였습니다, 플레이어2의 승리!\n");
					return 0;
			    }	
			}
			if (P2word[5] >= 0 || P1word[4] >= 0 || P1word[3] >= 0 || P1word[2] >= 0 || P1word[1] >= 0 || P1word[0] >= 0) {
				printf("플레이어1의 반칙으로 플레이어2의 승리!\n");
				break;
			}
			if (P2word[4] != P1word[0] || P2word[5] != P1word[1]) {
				printf("플레이어1이 틀렸습니다, 플레이어2의 승리!\n");
				break;
			}
			for (i = 0; P1word[i] != 0; i++) {
				WordList[i][NumberOfWords] = P1word[i];
			}
			NumberOfWords++;
		}
		else if (Turn == 1) {
			printf("  플레이어2의 턴 : %c%c : ", P1word[4], P1word[5]); scanf("%s", P2word); Turn = 0;
			for (i = 0; i < NumberOfWords; i++) {
				for (i2 = 0; i2 < 6; i2++) {
					if (WordList[i2][i] == P2word[i2]) Check++;
				}
				if (Check != 6) {
					Check = 0;
				}
				else {
					printf("플레이어2가 중복되는 단어를 사용하였습니다, 플레이어1의 승리!\n");
					return 0;
			    }
			}
			if (P2word[5] >= 0 || P1word[4] >= 0 || P1word[3] >= 0 || P1word[2] >= 0 || P1word[1] >= 0 || P1word[0] >= 0) {
				printf("플레이어2의 반칙으로 플레이어1의 승리!\n");
				break;
			}
			if (P1word[4] != P2word[0] || P1word[5] != P2word[1]) {
				printf("플레이어2가 틀렸습니다, 플레이어1의 승리!\n");
				break;
			}
			for (i = 0; P2word[i] != 0; i++) {
				WordList[i][NumberOfWords] = P2word[i];
			}
			NumberOfWords++;
	    }	
	} return 0;
}