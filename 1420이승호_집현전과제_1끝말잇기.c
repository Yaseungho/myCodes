#include <stdio.h>
int main() {
	int Turn = 0, NumberOfWords = 0, Check = 0, i, i2;
	char P1word[7] = { "" };
	char P2word[7] = { "��Ӹ�" };
	int WordList[6][100] = { 0 };
	printf("�����ձ⸦ �����մϴ�!\n�Է��ϴ� �ܾ�� 3���� �ѱ��̾�� �մϴ�.\n\n");
	printf("���� �ܾ�: ��Ӹ�\n\n�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n\n");
	while (1) {
		if (Turn == 0) {
			printf("�÷��̾�1�� �� : %c%c : ", P2word[4], P2word[5]); scanf("%s", P1word); Turn = 1;
			for (i = 0; i < NumberOfWords; i++) {
				Check = 0;
				for (i2 = 0; i2 < 6; i2++) {
					if (WordList[i2][i] == P1word[i2]) Check++;
				}
				if (Check != 6) {
					Check = 0;
				}
				else {
					printf("�÷��̾�1�� �ߺ��Ǵ� �ܾ ����Ͽ����ϴ�, �÷��̾�2�� �¸�!\n");
					return 0;
			    }	
			}
			if (P2word[5] >= 0 || P1word[4] >= 0 || P1word[3] >= 0 || P1word[2] >= 0 || P1word[1] >= 0 || P1word[0] >= 0) {
				printf("�÷��̾�1�� ��Ģ���� �÷��̾�2�� �¸�!\n");
				break;
			}
			if (P2word[4] != P1word[0] || P2word[5] != P1word[1]) {
				printf("�÷��̾�1�� Ʋ�Ƚ��ϴ�, �÷��̾�2�� �¸�!\n");
				break;
			}
			for (i = 0; P1word[i] != 0; i++) {
				WordList[i][NumberOfWords] = P1word[i];
			}
			NumberOfWords++;
		}
		else if (Turn == 1) {
			printf("  �÷��̾�2�� �� : %c%c : ", P1word[4], P1word[5]); scanf("%s", P2word); Turn = 0;
			for (i = 0; i < NumberOfWords; i++) {
				for (i2 = 0; i2 < 6; i2++) {
					if (WordList[i2][i] == P2word[i2]) Check++;
				}
				if (Check != 6) {
					Check = 0;
				}
				else {
					printf("�÷��̾�2�� �ߺ��Ǵ� �ܾ ����Ͽ����ϴ�, �÷��̾�1�� �¸�!\n");
					return 0;
			    }
			}
			if (P2word[5] >= 0 || P1word[4] >= 0 || P1word[3] >= 0 || P1word[2] >= 0 || P1word[1] >= 0 || P1word[0] >= 0) {
				printf("�÷��̾�2�� ��Ģ���� �÷��̾�1�� �¸�!\n");
				break;
			}
			if (P1word[4] != P2word[0] || P1word[5] != P2word[1]) {
				printf("�÷��̾�2�� Ʋ�Ƚ��ϴ�, �÷��̾�1�� �¸�!\n");
				break;
			}
			for (i = 0; P2word[i] != 0; i++) {
				WordList[i][NumberOfWords] = P2word[i];
			}
			NumberOfWords++;
	    }	
	} return 0;
}