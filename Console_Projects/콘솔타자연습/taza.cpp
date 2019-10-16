#include "taza.h"

void gotoxy(int x, int y);

void DropThread(int* Index, string WordValue, int RandNum, int Speed,
	           int Length, int* Life, string* WordArr,   
	           int* Key,  int* Level, bool* GameOver) {
	int i = 1;
	int Index1 = (*Index)++;
	//i는 반복문 돌리기용, index1은 이 스레드 함수의 고유번호

	gotoxy(RandNum, i);
	cout << WordValue;
	//랜덤 x좌표에 글자출력

	while (i != 23) {
		if (*GameOver) {
			*Index = 0;
			return;
		}
		//게임오버 상태일 시 스레드 종료

		int GetKey = *Key;
		//num을 계속 받음

		if(GetKey == Index1) {
			*Key = -1;
			gotoxy(RandNum, i);
			for (int j = 0; j < Length; j++) putchar(' ');
			return;
		}//글자맞추면 글자사라짐

		Sleep(Speed);
		gotoxy(RandNum, i++);
		for (int j = 0; j < Length; j++) putchar(' ');
		gotoxy(RandNum, ++i);
		cout << WordValue;
	} //화면에 글자 2칸씩 밑으로 떨어짐

	gotoxy(RandNum, i);
	for (int j = 0; j < Length; j++) putchar(' ');
	(*Life)--;
	gotoxy(25, 0);
	if (*Level >= 10) putchar(' ');
	cout << *Life << " ";
	//판정선까지 떨어질 시 글자 사라짐, Life감소

	*(WordArr + Index1) = "NONE";
	//WordArr의 인덱스 값 변경

	return;
}

void Word::Create() {
	string trash;
	ifstream WordIn("Words.txt");
	int RandNum = (rand() % NumberOfWords);
	for (int i = 0; i < RandNum; i++) WordIn >> trash;
	WordIn >> WordValue;
	Length = WordValue.size();
}//파일에 있는 단어중 랜덤으로 하나 가져오기

void Word::Drop(int* Life, string* WordArr, int* Key, int* Level, bool* GameOver, int* Index) {
	int RandNum = (rand() % 94) + 2;
	thread T(DropThread, Index, WordValue, 
			RandNum, Speed, Length, Life, 
			WordArr, Key, Level, GameOver);
	T.detach();
}

void JudgmentLine::CreateLine() {
	gotoxy(0, 22);
	for (int i = 0; i < 120; i++) cout << "─";
}//선긋기