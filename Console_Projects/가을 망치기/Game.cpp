#include "Game.h"

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView(char show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void FarmerMoveThread(Farmer* _farmer, Yusin* _yusin, Stage* _stage) {
	int Dup, Ddown, Dleft, Dright, result;
	while (_stage->Nrice && !(_stage->isGameover)) {
		Dup = 9999, Ddown = 9999, Dleft = 9999, Dright = 9999;
		if (_farmer->y > 1 && !(_stage->map[_farmer->x][_farmer->y - 1])) {
			Dup = abs(_yusin->x - _farmer->x) * abs(_yusin->x - _farmer->x) + abs(_yusin->y - (_farmer->y - 1)) * abs(_yusin->y - (_farmer->y - 1));
		}//위로 이동할때
		if (_farmer->y < 24 && !(_stage->map[_farmer->x][_farmer->y + 1])) {
			Ddown = abs(_yusin->x - _farmer->x) * abs(_yusin->x - _farmer->x) + abs(_yusin->y - (_farmer->y + 1)) * abs(_yusin->y - (_farmer->y + 1));
		}//아래로 이동할때
		if (_farmer->x > 2 && !(_stage->map[_farmer->x - 2][_farmer->y])) {
			Dleft = abs(_yusin->x - (_farmer->x - 2)) * abs(_yusin->x - (_farmer->x - 2)) + abs(_yusin->y - _farmer->y) * abs(_yusin->y - _farmer->y);
		}//왼쪽으로 이동할때
		if (_farmer->x < 78 && !(_stage->map[_farmer->x + 2][_farmer->y])) {
			Dright = abs(_yusin->x - (_farmer->x + 2)) * abs(_yusin->x - (_farmer->x + 2)) + abs(_yusin->y - _farmer->y) * abs(_yusin->y - _farmer->y);
		}//오른쪽으로 이동할때
		result = min(Dup, min(Ddown, min(Dleft, Dright)));
		if (result == Dup) {
			_farmer->y--;
			if (_yusin->x == _farmer->x && _yusin->y == _farmer->y) {
				_stage->isGameover = true;
				return;
			}
		}
		else if (result == Ddown) {
			_farmer->y++;
			if (_yusin->x == _farmer->x && _yusin->y == _farmer->y) {
				_stage->isGameover = true;
				return;
			}
		}
		else if (result == Dleft) {
			_farmer->x -= 2;
			if (_yusin->x == _farmer->x && _yusin->y == _farmer->y) {
				_stage->isGameover = true;
				return;
			}
		}
		else if (result == Dright) {
			_farmer->x += 2;
			if (_yusin->x == _farmer->x && _yusin->y == _farmer->y) {
				_stage->isGameover = true;
				return;
			}
		}
		Sleep(_farmer->speed);
	}
}

void YusinMoveThread(Yusin* _yusin, Stage* _stage) {
	char ch;
	while (_stage->Nrice && !(_stage->isGameover)) {
		ch = _getch();
		if (ch == 'w' || ch == 'W') {
			if (_yusin->y > 1) {
				_yusin->y--;
				_yusin->icon = "▲";
			}
		}
		else if (ch == 'a' || ch == 'A') {
			if (_yusin->x > 2) {
				_yusin->x -= 2; 
				_yusin->icon = "◀";
			}
		}
		else if (ch == 's' || ch == 'S') {
			if (_yusin->y < 24) {
				_yusin->y++;
				_yusin->icon = "▼";
			}
		}
		else if (ch == 'd' || ch == 'D') {
			if (_yusin->x < 78) {
				_yusin->x += 2;
				_yusin->icon = "▶";
			}
		}
		if (_stage->map[_yusin->x][_yusin->y]) {
			_stage->Nrice--;
			_stage->map[_yusin->x][_yusin->y] = 0;
		}
		Sleep(50);
	}
	return;
}

void StartScreen::show(vector<Stage*>& _Stages, int* NowStage) {
	char ch = '0';
	system("cls");
	gotoxy(0, 0);
	cout << "┌"; for (int i = 0; i < 79; i++) cout << "─"; cout << "┐";
	for (int i = 1; i < 25; i++) {
		gotoxy(0, i); cout << "│";
		gotoxy(80, i); cout << "│";
	}
	cout << "\n└"; for (int i = 0; i < 79; i++) cout << "─"; cout << "┘";//25 * 79
	gotoxy(8, 1);
	cout << " .______       __    __   __  .__   __.  __  .__   __.   _______";
	gotoxy(8, 2);
	cout << "|   _  \\     |  |  |  | |  | |  \\ |  | |  | |  \\ |  |  /  _____|";
	gotoxy(8, 3);
	cout << "|  |_)  |    |  |  |  | |  | |   \\|  | |  | |   \\|  | |  |  __ ";
	gotoxy(8, 4);
	cout << "|      /     |  |  |  | |  | |  . `  | |  | |  . `  | |  | |_ |";
	gotoxy(8, 5);
	cout << "|  |\\  \\----.|  `--'  | |  | |  |\\   | |  | |  |\\   | |  |__| |";
	gotoxy(8, 6);
	cout << "| _| `._____| \\______/  |__| |__| \\__| |__| |__| \\__|  \\______|";
	gotoxy(5, 8);
	cout << "     ___       __    __  .___________. __    __  .___  ___. .__   __. ";
	gotoxy(5, 9);
	cout << "    /   \\     |  |  |  | |           ||  |  |  | |   \\/   | |  \\ |  | ";
	gotoxy(5, 10);
	cout << "   /  ^  \\    |  |  |  | `---|  |----`|  |  |  | |  \\  /  | |   \\|  | ";
	gotoxy(5, 11);
	cout << "  /  /_\\  \\   |  |  |  |     |  |     |  |  |  | |  |\\/|  | |  . `  | ";
	gotoxy(5, 12);
	cout << " /  _____  \\  |  `--'  |     |  |     |  `--'  | |  |  |  | |  |\\   | ";
	gotoxy(5, 13);
	cout << "/__/     \\__\\  \\______/      |__|      \\______/  |__|  |__| |__| \\__| ";
	gotoxy(25, 18);
	cout << "E N T E R	T O	S T A R T";
	while (ch != 13) ch = _getch();
}

void SelectScreen::show(vector<Stage*>& _Stages, int* NowStage) {
	system("cls");
	gotoxy(0, 0);
	cout << "┌"; for (int i = 0; i < 79; i++) cout << "─"; cout << "┐";
	for (int i = 1; i < 25; i++) {
		gotoxy(0, i); cout << "│";
		gotoxy(80, i); cout << "│";
	}
	cout << "\n└"; for (int i = 0; i < 79; i++) cout << "─"; cout << "┘";//25 * 79

	gotoxy(10, 5);
	cout << "스 테 이 지	선 택 :";
	gotoxy(18, 10);
	cout << "스테이지 1 <";
	if (_Stages[0]->isClear) cout << " (clear)";
	gotoxy(18, 14);
	cout << "스테이지 2  ";
	if (_Stages[1]->isClear) cout << " (clear)";
	gotoxy(18, 18);
	cout << "스테이지 3  ";
	if (_Stages[2]->isClear) cout << " (clear)";
	int GetKey = 0;
	int GetStage = 1;
	int temp, temp2;
	while (1) {
		GetKey = _getch();
		if (GetKey == 'S' || GetKey == 's') {
			if (GetStage < 3) {
				GetStage++;
				if (GetStage == 3) {
					gotoxy(29, 14);
					cout << " ";
					gotoxy(29, 18);
					cout << "<";
				}
				else {
					gotoxy(29, 10);
					cout << " ";
					gotoxy(29, 14);
					cout << "<";
				}
			}
		} //상단 키 입력시
		else if (GetKey == 'W' || GetKey == 'w') {
			if (GetStage > 1) {
				GetStage--;
				if (GetStage == 1) {
					gotoxy(29, 14);
					cout << " ";
					gotoxy(29, 10);
					cout << "<";
				}
				else {
					gotoxy(29, 18);
					cout << " ";
					gotoxy(29, 14);
					cout << "<";
				}
			}
		} //하단 키 입력시
		else if (GetKey == 13) {
			try {
				temp = GetStage - 2;
				temp2 = GetStage - 1;
				if (1 < GetStage) {
					if (!(_Stages[temp]->isClear)) throw((string)"ERROR_NOT_CLEARED");
				}

				if (_Stages[temp2]->isClear) throw(1);
				else break;
			}
			catch (string expn) {
				gotoxy(10, 22);
				cout << expn << " : 이전 스테이지를 먼저 클리어하세요		";
			}
			catch (int expn) {
				gotoxy(10, 22);
				cout << "ERROR_ALREADY_CLEARED : 이미 클리어된 스테이지입니다		";
			}
		} //엔터 키 입력시
	}
	*NowStage = GetStage - 1;
}

void InGameScreen::show(vector<Stage*>& _Stages, int* NowStage) {
	system("cls");
	gotoxy(0, 0);
	cout << "┌"; for (int i = 0; i < 79; i++) cout << "─"; cout << "┐";
	for (int i = 1; i < 25; i++) {
		gotoxy(0, i); cout << "│";
		gotoxy(80, i); cout << "│";
	}
	cout << "\n└"; for (int i = 0; i < 79; i++) cout << "─"; cout << "┘";//25 * 79

	for (int i = 0; i < 79; i++) {
		for (int j = 0; j < 25; j++) {
			if (stage->map[i][j]) {
				gotoxy(i, j);
				cout << "♨";
			}
		}
	}
	gotoxy(0, 26);
	cout << "남은 벼 갯수 : " << stage->Nrice;

	for (auto& v : stage->Farmers) {
		gotoxy(v->x, v->y);
		cout << "♣";
	}
	
	gotoxy(yusin->x, yusin->y);
	cout << yusin->icon;
	thread T1([&](Yusin* _yusin) { YusinMoveThread(_yusin, stage); }, yusin);
	T1.detach();
	for (auto& v : stage->Farmers) {
		thread T2([&](Farmer* _farmer, Yusin* _yusin) { FarmerMoveThread(_farmer, _yusin, stage); }, v, yusin);
		T2.detach();
	}
}

void InGameScreen::update() {
	if (!(stage->Nrice)) {
		Sleep(1000);
		stage->isClear = true;
		over = 1;
	}
	if (stage->isGameover) {
		Sleep(1000);
		stage->isGameover = false;
		over = 2;
	}
	system("cls");
	gotoxy(0, 0);
	cout << "┌"; for (int i = 0; i < 79; i++) cout << "─"; cout << "┐";
	for (int i = 1; i < 25; i++) {
		gotoxy(0, i); cout << "│";
		gotoxy(80, i); cout << "│";
	}
	cout << "\n└"; for (int i = 0; i < 79; i++) cout << "─"; cout << "┘";//25 * 79

	for (int i = 1; i < 79; i++) {
		for (int j = 1; j < 25; j++) {
			if (stage->map[i][j]) {
				gotoxy(i, j);
				cout << "♨";
			}
		}
	}

	gotoxy(0, 26);
	cout << "남은 벼 갯수 : " << stage->Nrice;

	for (auto& v : stage->Farmers) {
		gotoxy(v->x, v->y);
		cout << "♣";
	}

	gotoxy(yusin->x, yusin->y);
	cout << yusin->icon;
}

void GameClearScreen::show(vector<Stage*>& _Stages, int* NowStage) {
	system("cls");
	int ch = 0;
	gotoxy(0, 0);
	cout << "┌"; for (int i = 0; i < 79; i++) cout << "─"; cout << "┐";
	for (int i = 1; i < 25; i++) {
		gotoxy(0, i); cout << "│";
		gotoxy(80, i); cout << "│";
	}
	cout << "\n└"; for (int i = 0; i < 79; i++) cout << "─"; cout << "┘";//25 * 79

	gotoxy(10, 5);
	cout << "  ______  __       _______      ___      .______          __  ";
	gotoxy(10, 6);
	cout << " /      ||  |     |   ____|    /   \\     |   _  \\        |  | ";
	gotoxy(10, 7);
	cout << "|  ,----'|  |     |  |__      /  ^  \\    |  |_)  |       |  | ";
	gotoxy(10, 8);
	cout << "|  |     |  |     |   __|    /  /_\\  \\   |      /        |  | ";
	gotoxy(10, 9);
	cout << "|  `----.|  `----.|  |____  /  _____  \\  |  |\\  \\----.   |__| ";
	gotoxy(10, 10);
	cout << " \\______||_______||_______|/__/     \\__\\ | _| `._____|   (__) ";
	gotoxy(20, 15);
	cout << "E N T E R    T O    N E X T    S T A G E";
	while (ch != 13) ch = _getch();
}

void GameOverScreen::show(vector<Stage*>& _Stages, int* NowStage) {
	system("cls");
	gotoxy(0, 0);
	cout << "┌"; for (int i = 0; i < 79; i++) cout << "─"; cout << "┐";
	for (int i = 1; i < 25; i++) {
		gotoxy(0, i); cout << "│";
		gotoxy(80, i); cout << "│";
	}
	cout << "\n└"; for (int i = 0; i < 79; i++) cout << "─"; cout << "┘";//25 * 79

	gotoxy(16, 3);
	cout << "  _______      ___      .___  ___.  _______ ";
	gotoxy(16, 4);
	cout << " /  _____|    /   \\     |   \\/   | |   ____|";
	gotoxy(16, 5);
	cout << "|  |  __     /  ^  \\    |  \\  /  | |  |__   ";
	gotoxy(16, 6);
	cout << "|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __ | ";
	gotoxy(16, 7);
	cout << "|  |__| |  /  _____  \\  |  |  |  | |  |____ ";
	gotoxy(16, 8);
	cout << " \\______| /__/     \\__\\ |__|  |__| |_______|";
	gotoxy(16, 10);
	cout << "  ______   ____    ____  _______ .______      ";
	gotoxy(16, 11);
	cout << " /  __  \\  \\   \\  /   / |   ____||   _  \\     ";
	gotoxy(16, 12);
	cout << "|  |  |  |  \\   \\/   /  |  |__   |  |_)  |    ";
	gotoxy(16, 13);
	cout << "|  |  |  |   \\      /   |   __|  |      /     ";
	gotoxy(16, 14);
	cout << "|  `--'  |    \\    /    |  |____ |  |\\  \\----.";
	gotoxy(16, 15);
	cout << " \\______/      \\__/     |_______|| _| `._____|";

	gotoxy(30, 20); cout << "다시 하시겠습니까?";
	gotoxy(28, 22); cout << ">예     /    아니오";
	gotoxy(28, 22);
	char GetKey = '0';
	while (GetKey != 13) {
		GetKey = _getch();
		if (GetKey == 'A' || GetKey == 'a') {
			gotoxy(40, 22); cout << " ";
			gotoxy(28, 22); cout << ">";
			Retry = true;
		}
		else if (GetKey == 'D' || GetKey == 'd') {
			gotoxy(28, 22); cout << " ";
			gotoxy(40, 22); cout << ">";
			Retry = false;
		}
	}
}

void EndingScreen::show(vector<Stage*>& _Stages, int* NowStage) {
	int ch = 0;
	gotoxy(10, 5);
	cout << ".___________. __    __   _______     _______ .__   __.  _______  ";
	Sleep(500);
	gotoxy(10, 6);
	cout << "|           ||  |  |  | |   ____|   |   ____||  \\ |  | |       \\ ";
	Sleep(500);
	gotoxy(10, 7);
	cout << "`---|  |----`|  |__|  | |  |__      |  |__   |   \\|  | |  .--.  |";
	Sleep(500);
	gotoxy(10, 8);
	cout << "    |  |     |   __   | |   __|     |   __|  |  . `  | |  |  |  |";
	Sleep(500);
	gotoxy(10, 9);
	cout << "    |  |     |  |  |  | |  |____    |  |____ |  |\\   | |  '--'  |";
	Sleep(500);
	gotoxy(10, 10);
	cout << "    |__|     |__|  |__| |_______|   |_______||__| \\__| |_______/ ";
	Sleep(500);
	gotoxy(20, 15);
	cout << "       E N T E R    T O    C L O S E          ";
	while (ch != 13) ch = _getch();                                                           
}