// 콘솔 타자연습
// 만든놈 : 1420 이승호
// PROGECT CG+
#include "taza.h"

void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
} //콘솔창 포인터 위치이동 함수

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
} //0 넣을시 커서숨김, 1 넣을시 커서보여줌

bool RetryEvent() {
	bool Retry = 0;
	//0 : 다시하기 | 1 : 종료

	gotoxy(30, 11); cout << "다시 하시겠습니까?";
	gotoxy(28, 13); cout << ">예     /    아니오";
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
} //게임오버 되었을 때 선택지 출력

void LevelThread(bool* GameOver, int* Level) {
	while (*Level != 11) {
		for (int i = 0; i < 200; i++) {
			if (*GameOver) return;
			//게임오버 상태일 시 스레드 종료
			Sleep(100);
		}
		(*Level)++;
		gotoxy(0, 0);
		if (*Level == 11) cout << "MAX";
		else cout << *Level;
	}
} //약 20초마다 Level 증가

void InputTheWord(bool* GameOver, int* Score, int* Level, int* Key, string* WordArr) {
	int i, ind;
	char Ch;
	string InputWord;
	ind = 0;
	Ch = 0;
	//i는 반복문 돌리기용   ind, Ch, InputWord는 문자입력용 변수

	if (*GameOver) return;
	//게임오버 상태일 시 스레드 종료

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
	//_getch를 이용해 입력받는 부분

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
	}//정답인지 아닌지 확인하는 연산

	thread T2(InputTheWord, GameOver, Score, Level, Key, WordArr);
	T2.detach();
	//함수 재호출
	return;
}
		
void CreateStartWindow(int* Level) {
	system("cls");
	gotoxy(0, 0);
	cout << "┌"; for (int i = 0; i < 78; i++) cout << "─"; cout << "┐";
	for (int i = 1; i < 25; i++) {
		gotoxy(0,i); cout << "│";
		gotoxy(79, i); cout << "│";
	}
	cout << "\n└"; for (int i = 0; i < 78; i++) cout << "─"; cout << "┘";
	gotoxy(33, 10);
	cout << "콘솔 타자연습";
	gotoxy(33, 12);
	//시작 화면 출력

	cout << "단계 설정 : 1단계 ↑";
	int GetKey = 0;
	while (GetKey != 13) {
		if (_kbhit()) {
			GetKey = _getch();
			if (GetKey == 224) {
				GetKey = _getch();
				if (GetKey == 72) {
					if (*Level != 10) (*Level)++;
					gotoxy(45, 12);
					if (*Level == 10) cout << *Level << "단계 ↓";
					else cout << *Level << "단계 ↕";
				}
				else if (GetKey == 80) {
					if (*Level > 1) (*Level)--;
					gotoxy(45, 12);
					if (*Level == 1) cout << *Level << "단계 ↑";
					else cout << *Level << "단계 ↕";
					//난이도 조절
	}   }   }   }
}

void CreateIngameWindow(int* Level) {
	int Life = 10, Score = 0, Key = -1, Index = 0, Ind = 0;
	bool GameOver = 0;
	string WordArr[300];

	system("cls");
	gotoxy(0, 0);
	cout << *Level << " 단계  │  남은 생명력 : " << Life;
	gotoxy(0, 26);
	cout << "점수 : " << Score;

	JudgmentLine Judge;
	Judge.CreateLine();
	//인게임 UI출력

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
	} //게임 진행

	GameOver = true;

	keybd_event(0x0D, 0, 0, 0);
	keybd_event(0x0D, 0, 0 | KEYEVENTF_KEYUP, 0);
	//앤터키 입력이밴트 발생함수 : InputTheWord 스레드가 완전히 종료됨.

	Sleep(100);
	system("cls");
	gotoxy(0, 0);
	cout << "┌"; for (int i = 0; i < 78; i++) cout << "─"; cout << "┐";
	for (int i = 1; i < 25; i++) {
		gotoxy(0, i); cout << "│";
		gotoxy(79, i); cout << "│";
	}
	cout << "\n└"; for (int i = 0; i < 78; i++) cout << "─"; cout << "┘";
	gotoxy(35, 9);
	if (Score >= 500) cout << "게임 클리어!";
	else {
		gotoxy(30, 9);
		cout << "게임 오버! 점수 : " << Score;
	}
	//게임 끝난 후 창 출력
}

int main() {
	srand(time(NULL));
	CursorView(0);//커서 숨기기
	while (1) {
		int Level = 1;
		CreateStartWindow(&Level);//시작화면
		CreateIngameWindow(&Level);//인게임
		if (RetryEvent()) break;//다시하기 선택지
		Level = 1;
	}
	gotoxy(0, 26);
	return 0;
}