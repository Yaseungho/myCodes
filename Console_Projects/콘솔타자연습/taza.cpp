#include "taza.h"

void gotoxy(int x, int y);

void DropThread(int* Index, string WordValue, int RandNum, int Speed,
	           int Length, int* Life, string* WordArr,   
	           int* Key,  int* Level, bool* GameOver) {
	int i = 1;
	int Index1 = (*Index)++;
	//i�� �ݺ��� �������, index1�� �� ������ �Լ��� ������ȣ

	gotoxy(RandNum, i);
	cout << WordValue;
	//���� x��ǥ�� �������

	while (i != 23) {
		if (*GameOver) {
			*Index = 0;
			return;
		}
		//���ӿ��� ������ �� ������ ����

		int GetKey = *Key;
		//num�� ��� ����

		if(GetKey == Index1) {
			*Key = -1;
			gotoxy(RandNum, i);
			for (int j = 0; j < Length; j++) putchar(' ');
			return;
		}//���ڸ��߸� ���ڻ����

		Sleep(Speed);
		gotoxy(RandNum, i++);
		for (int j = 0; j < Length; j++) putchar(' ');
		gotoxy(RandNum, ++i);
		cout << WordValue;
	} //ȭ�鿡 ���� 2ĭ�� ������ ������

	gotoxy(RandNum, i);
	for (int j = 0; j < Length; j++) putchar(' ');
	(*Life)--;
	gotoxy(25, 0);
	if (*Level >= 10) putchar(' ');
	cout << *Life << " ";
	//���������� ������ �� ���� �����, Life����

	*(WordArr + Index1) = "NONE";
	//WordArr�� �ε��� �� ����

	return;
}

void Word::Create() {
	string trash;
	ifstream WordIn("Words.txt");
	int RandNum = (rand() % NumberOfWords);
	for (int i = 0; i < RandNum; i++) WordIn >> trash;
	WordIn >> WordValue;
	Length = WordValue.size();
}//���Ͽ� �ִ� �ܾ��� �������� �ϳ� ��������

void Word::Drop(int* Life, string* WordArr, int* Key, int* Level, bool* GameOver, int* Index) {
	int RandNum = (rand() % 94) + 2;
	thread T(DropThread, Index, WordValue, 
			RandNum, Speed, Length, Life, 
			WordArr, Key, Level, GameOver);
	T.detach();
}

void JudgmentLine::CreateLine() {
	gotoxy(0, 22);
	for (int i = 0; i < 120; i++) cout << "��";
}//���߱�