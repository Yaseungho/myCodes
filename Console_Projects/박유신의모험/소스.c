#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void PrintScripts(char* filePTR) {
	char Say[50] = { 0 };
	int i = 0;
	gotoxy(4, 22);
	while (1) {
		fscanf(filePTR, "%s", Say);
		for (i = 0; Say[i] != 0; i++) {
			printf("%c", Say[i]);
			Sleep(30);
			if (Say[i] == '.' || Say[i] == '!' || Say[i] == '?') return;
		} printf(" ");
		Sleep(30);
	}
}

void DeleteScripts(char* filePTR){
	char Trash[50];
	while (1) {
		fscanf(filePTR, "%s", Trash);
		for (int i = 0; Trash[i] != 0; i++) {
			if (Trash[i] == '.' || Trash[i] == '!' || Trash[i] == '?') return;
		}
	}
}

void ShowPicture(char* filePTR) {
	gotoxy(0, 0);
	for (int i = 0; i < 20; i++) {
		char Image[71];
		fscanf(filePTR, "%s", Image);
		printf("%s\n", Image);
	} return 0;
}

void CleanWindow() {
	gotoxy(2, 22);
	for (int i = 0; i < 68; i++) printf(" ");
	gotoxy(2, 23);
	for (int i = 0; i < 68; i++) printf(" ");
	gotoxy(2, 24);
	for (int i = 0; i < 68; i++) printf(" ");
	gotoxy(2, 25);
	for (int i = 0; i < 68; i++) printf(" ");
	gotoxy(2, 22);
	return;
}

void MakeChoice() {
	gotoxy(25, 7);
	//�̹��� ȭ�� �߾��ʿ� ������ 2��
	printf("��");
	for (int i = 0; i < 19; i++) printf("��");
	printf("��");
	gotoxy(25, 8);
	printf("��");
	for (int i = 0; i < 19; i++) printf(" ");
	printf("��");
	gotoxy(25, 9);
	printf("��");
	for (int i = 0; i < 19; i++) printf(" ");
	printf("��");
	gotoxy(25, 10);
	printf("��");
	for (int i = 0; i < 19; i++) printf("��");
	printf("��");
	gotoxy(25, 13);
	printf("��");
	for (int i = 0; i < 19; i++) printf("��");
	printf("��");
	gotoxy(25, 14);
	printf("��");
	for (int i = 0; i < 19; i++) printf(" ");
	printf("��");
	gotoxy(25, 15);
	printf("��");
	for (int i = 0; i < 19; i++) printf(" ");
	printf("��");
	gotoxy(25, 16);
	printf("��");
	for (int i = 0; i < 19; i++) printf("��");
	printf("��");
}

void Choice1() {
	gotoxy(27, 8);
	printf("1 �Է�");
	gotoxy(27, 9);
	printf("������ �����´�.");
	gotoxy(27, 14);
	printf("2 �Է�");
	gotoxy(27, 15);
	printf("�ɾ�ڰ� �Ѵ�.");
}
void Choice2() {
	gotoxy(27, 8);
	printf("1 �Է�");
	gotoxy(27, 9);
	printf("�ڵ庼�� ��ǥ�Ѵ�.");
	gotoxy(27, 14);
	printf("2 �Է�");
	gotoxy(27, 15);
	printf("�Ǳ��� ��ǥ�Ѵ�.");
}

int main() {
	FILE* filePTR1 = fopen("�뺻.txt", "r");
	FILE* filePTR2 = fopen("�뺻_������1.txt", "r");
	FILE* Bus_Stop = fopen("���_����������.txt", "r");
	FILE* Gym = fopen("���_ü����.txt", "r");
	FILE* ArtRoom = fopen("���_�̼���.txt", "r");
	char daedap = 10;
	int isTF;
	printf("   ______               _     __   __         _____  _         _       \n");
	printf("   | ___ \\             | |    \\ \\ / /        /  ___|(_)       ( )      \n");
	printf("   | |_/ /  __ _  _ __ | | __  \\ V /  _   _  \\ `--.  _  _ __  |/  ___  \n");
	printf("   |  __/  / _` || '__|| |/ /   \\ /  | | | |  `--. \\| || '_ \\    / __| \n");
	printf("   | |    | (_| || |   |   <    | |  | |_| | /\\__/ /| || | | |   \\__ \\ \n");
	printf("   \\_|     \\__,_||_|   |_|\\_\\   \\_/   \\__,_| \\____/ |_||_| |_|   |___/ \n");
	printf("     ___       _                      _                       \n");
	printf("    / _ \\     | |                    | |                      \n");
	printf("   / /_\\ \\  __| |__   __  ___  _ __  | |_  _   _  _ __   ___  \n");
	printf("   |  _  | / _` |\\ \\ / / / _ \\| '_ \\ | __|| | | || '__| / _ \\ \n");
	printf("   | | | || (_| | \\ V / |  __/| | | || |_ | |_| || |   |  __/ \n");
	printf("   \\_| |_/ \\__,_|  \\_/   \\___||_| |_| \\__| \\__,_||_|    \\___| \n");
	gotoxy(17, 17);
	printf("�����Ϸ��� �ƹ� Ű�� �����ÿ�..");
	scanf("%c", &daedap);
	system("cls");
	//�̹��� 20*70 �뺻 5*70 ���
	for (int i = 0; i < 20; i++) printf("\n");
	printf("��");
	for (int i = 0; i < 70; i++) printf("��"); 
	printf("��\n");
	for (int i = 0; i < 5; i++) {
		printf("��");
		gotoxy(71, 21 + i);
		printf("��\n");
	} printf("��");
	for (int i = 0; i < 70; i++) printf("��");
	printf("��\n");
	//�̹��� 20*70 �뺻 5*70 ���
	PrintScripts(filePTR1); 
	gotoxy(60, 24);
	printf("ENTER");
	while (1) {
		daedap = 0;
		scanf("%c", &daedap);
		if (daedap == 10) break;
		else {
			gotoxy(66, 24);
			printf(" ");
			gotoxy(66, 24);
		}
	}
	for (int i = 0; i < 9; i++) {
		CleanWindow();
		PrintScripts(filePTR1);
		gotoxy(60, 24);
		printf("ENTER");
		while (1) {
			daedap = 0;
			scanf("%c", &daedap);
			if (daedap == 10) break;
			else {
				gotoxy(66, 24);
				printf(" ");
				gotoxy(66, 24);
			}
		}
	}//��� �غ��ϴ� ������
	ShowPicture(Bus_Stop);
	Bus_Stop = fopen("���_����������.txt", "r");
	for (int i = 0; i < 5; i++) {
		CleanWindow();
		PrintScripts(filePTR1);
		gotoxy(60, 24);
		printf("ENTER");
		while (1) {
			daedap = 0;
			scanf("%c", &daedap);
			if (daedap == 10) break;
			else {
				gotoxy(66, 24);
				printf(" ");
				gotoxy(66, 24);
			}
		}
	}//��������� ����

	CleanWindow();
	PrintScripts(filePTR1);
	MakeChoice();
	Choice1();
	gotoxy(66, 24);
	while (1) {
		daedap = 0;
		scanf("%c", &daedap);
		if (daedap == '1') {
			isTF = 0;
			break;
		}
		if (daedap == '2') {
			isTF = 1;
			break;
		}
		else {
			gotoxy(66, 24);
			printf(" ");
			gotoxy(66, 24);
		}
	}//���� �ΰ��, ������
	ShowPicture(Bus_Stop);
	Bus_Stop = fopen("���_����������.txt", "r");
	for (int i = 0; i < 5; i++) {
		CleanWindow();
		if (isTF) {
			PrintScripts(filePTR1);
			DeleteScripts(filePTR2);
		}
		else {
			PrintScripts(filePTR2);
			DeleteScripts(filePTR1);
		}
		gotoxy(60, 24);
		printf("ENTER");
		while (1) {
			daedap = 0;
			scanf("%c", &daedap);
			if (daedap == 10) break;
			else {
				gotoxy(66, 24);
				printf(" ");
				gotoxy(66, 24);
			}
		}
	}//���ÿ� ���� �޶����� �뺻5��
	ShowPicture(Gym);
	Gym = fopen("���_ü����.txt", "r");
	for (int i = 0; i < 8; i++) {
		CleanWindow();
		PrintScripts(filePTR1);
		gotoxy(60, 24);
		printf("ENTER");
		while (1) {
			daedap = 0;
			scanf("%c", &daedap);
			if (daedap == 10) break;
			else {
				gotoxy(66, 24);
				printf(" ");
				gotoxy(66, 24);
			}
		}
	}//� ����
	CleanWindow();
	PrintScripts(filePTR1);
	MakeChoice();
	Choice2();
	gotoxy(66, 24);
	while (1) {
		daedap = 0;
		scanf("%c", &daedap);
		if (daedap == '1') {
			isTF = 0;
			break;
		}
		if (daedap == '2') {
			isTF = 1;
			break;
		}
		else {
			gotoxy(66, 24);
			printf(" ");
			gotoxy(66, 24);
		}
	}//ü���ð�, ������2
	ShowPicture(Gym);
	Gym = fopen("���_ü����.txt", "r");
	for (int i = 0; i < 4; i++) {
		CleanWindow();
		if (isTF) {
			PrintScripts(filePTR1);
			DeleteScripts(filePTR2);
		}
		else {
			PrintScripts(filePTR2);
			DeleteScripts(filePTR1);
		}
		gotoxy(60, 24);
		printf("ENTER");
		while (1) {
			daedap = 0;
			scanf("%c", &daedap);
			if (daedap == 10) break;
			else {
				gotoxy(66, 24);
				printf(" ");
				gotoxy(66, 24);
			}
		}
	}//���ÿ� ���� �޶����� �뺻 4��
	ShowPicture(ArtRoom);
	ArtRoom = fopen("���_�̼���.txt", "r");
	for (int i = 0; i < 18; i++) {
		CleanWindow();
		PrintScripts(filePTR1);
		gotoxy(60, 24);
		printf("ENTER");
		while (1) {
			daedap = 0;
			scanf("%c", &daedap);
			if (daedap == 10) break;
			else {
				gotoxy(66, 24);
				printf(" ");
				gotoxy(66, 24);
			}
		}
	}//���ǽǰ���
	fclose(filePTR1);
	fclose(filePTR2);
	fclose(Bus_Stop);
	fclose(Gym);
	fclose(ArtRoom);
	gotoxy(0, 26);
	return 0;
}