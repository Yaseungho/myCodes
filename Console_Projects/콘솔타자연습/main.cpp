// �ܼ� Ÿ�ڿ���
// ����� : 1420 �̽�ȣ
// PROGECT CG+
#include "taza.h"

void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
} //�ܼ�â ������ ��ġ�̵� �Լ�

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
} //0 ������ Ŀ������, 1 ������ Ŀ��������

bool RetryEvent() {
	bool Retry = 0;
	//0 : �ٽ��ϱ� | 1 : ����

	gotoxy(30, 11); cout << "�ٽ� �Ͻðڽ��ϱ�?";
	gotoxy(28, 13); cout << ">��     /    �ƴϿ�";
	gotoxy(28, 13);
	int GetKey = 0;
	while (GetKey != 13) {
		if (_kbhit()) {
			GetKey = _getch();
			if (GetKey == 224) {
				GetKey = _getch();
				if (GetKey == 75) {
					gotoxy(40, 13); cout << " ";
					gotoxy(28, 13); cout << ">";
					Retry = false;
				}
				else if (GetKey == 77) {
					gotoxy(28, 13); cout << " ";
					gotoxy(40, 13); cout << ">";
					Retry = true;
	}	}	}	}
	return Retry;
} //���ӿ��� �Ǿ��� �� ������ ���

void LevelThread(bool* GameOver, int* Level) {
	while (*Level != 11) {
		for (int i = 0; i < 200; i++) {
			if (*GameOver) return;
			//���ӿ��� ������ �� ������ ����
			Sleep(100);
		}
		(*Level)++;
		gotoxy(0, 0);
		if (*Level == 11) cout << "MAX";
		else cout << *Level;
	}
} //�� 20�ʸ��� Level ����

void InputTheWord(bool* GameOver, int* Score, int* Level, int* Key, string* WordArr) {
	int i, ind;
	char Ch;
	string InputWord;
	ind = 0;
	Ch = 0;
	//i�� �ݺ��� �������   ind, Ch, InputWord�� �����Է¿� ����

	if (*GameOver) return;
	//���ӿ��� ������ �� ������ ����

	while (1) {
		Ch = _getch();
		if (Ch == 8 && ind) {
			InputWord.pop_back();
			gotoxy(--ind, 24);
			printf(" ");
			gotoxy(ind, 24);
		}
		else if (Ch == 13) break;
		else {
			InputWord.push_back(Ch);
			gotoxy(ind++, 24);
			putchar(Ch);
		}
	} gotoxy(0, 24); 
	for (int i = 0; i < InputWord.size(); i++) printf(" ");
	//_getch�� �̿��� �Է¹޴� �κ�

	i = 0;
	if (InputWord != "NONE" && InputWord != "\0") {
		for (int i = 0; i < 300; i++) {
			if (WordArr[i] == InputWord) {
				*Score += *Level;
				*Key = i;
				WordArr[i] = "NONE";
				gotoxy(7, 26); printf("%d", *Score);
				break;
			}
		}
	}//�������� �ƴ��� Ȯ���ϴ� ����

	thread T2(InputTheWord, GameOver, Score, Level, Key, WordArr);
	T2.detach();
	//�Լ� ��ȣ��
	return;
}
		
void CreateStartWindow(int* Level) {
	system("cls");
	gotoxy(0, 0);
	cout << "��"; for (int i = 0; i < 78; i++) cout << "��"; cout << "��";
	for (int i = 1; i < 25; i++) {
		gotoxy(0,i); cout << "��";
		gotoxy(79, i); cout << "��";
	}
	cout << "\n��"; for (int i = 0; i < 78; i++) cout << "��"; cout << "��";
	gotoxy(33, 10);
	cout << "�ܼ� Ÿ�ڿ���";
	gotoxy(33, 12);
	//���� ȭ�� ���

	cout << "�ܰ� ���� : 1�ܰ� ��";
	int GetKey = 0;
	while (GetKey != 13) {
		if (_kbhit()) {
			GetKey = _getch();
			if (GetKey == 224) {
				GetKey = _getch();
				if (GetKey == 72) {
					if (*Level != 10) (*Level)++;
					gotoxy(45, 12);
					if (*Level == 10) cout << *Level << "�ܰ� ��";
					else cout << *Level << "�ܰ� ��";
				}
				else if (GetKey == 80) {
					if (*Level > 1) (*Level)--;
					gotoxy(45, 12);
					if (*Level == 1) cout << *Level << "�ܰ� ��";
					else cout << *Level << "�ܰ� ��";
					//���̵� ����
	}   }   }   }
}

void CreateIngameWindow(int* Level) {
	int Life = 10, Score = 0, Key = -1, Index = 0, Ind = 0;
	bool GameOver = 0;
	string WordArr[300];

	system("cls");
	gotoxy(0, 0);
	cout << *Level << " �ܰ�  ��  ���� ����� : " << Life;
	gotoxy(0, 26);
	cout << "���� : " << Score;

	JudgmentLine Judge;
	Judge.CreateLine();
	//�ΰ��� UI���

	thread T1(LevelThread, &GameOver, Level);
	T1.detach();

	Word Word1;
	Word1.Create();
	thread T2(InputTheWord, &GameOver, &Score, Level, &Key, WordArr);
	T2.detach();
	Word1.Speed = 1000 / *Level + 150;
	WordArr[Ind] = Word1.WordValue;
	Word1.Drop(&Life, WordArr, &Key, Level, &GameOver, &Index);
	Ind++;
	Sleep(Word1.Speed * 6);
	while (Life && Score < 500) {
		Word Word1;
		Word1.Create();
		Word1.Speed = 1000 / *Level + 150;
		WordArr[Ind] = Word1.WordValue;
		Word1.Drop(&Life, WordArr, &Key, Level, &GameOver, &Index);
		Ind++;
		Sleep(Word1.Speed * 6);
	} //���� ����

	GameOver = true;

	keybd_event(0x0D, 0, 0, 0);
	keybd_event(0x0D, 0, 0 | KEYEVENTF_KEYUP, 0);
	//����Ű �Է��̹�Ʈ �߻��Լ� : InputTheWord �����尡 ������ �����.

	Sleep(100);
	system("cls");
	gotoxy(0, 0);
	cout << "��"; for (int i = 0; i < 78; i++) cout << "��"; cout << "��";
	for (int i = 1; i < 25; i++) {
		gotoxy(0, i); cout << "��";
		gotoxy(79, i); cout << "��";
	}
	cout << "\n��"; for (int i = 0; i < 78; i++) cout << "��"; cout << "��";
	gotoxy(35, 9);
	if (Score >= 500) cout << "���� Ŭ����!";
	else {
		gotoxy(30, 9);
		cout << "���� ����! ���� : " << Score;
	}
	//���� ���� �� â ���
}

int main() {
	srand(time(NULL));
	CursorView(0);//Ŀ�� �����
	while (1) {
		int Level = 1;
		CreateStartWindow(&Level);//����ȭ��
		CreateIngameWindow(&Level);//�ΰ���
		if (RetryEvent()) break;//�ٽ��ϱ� ������
		Level = 1;
	}
	gotoxy(0, 26);
	return 0;
}