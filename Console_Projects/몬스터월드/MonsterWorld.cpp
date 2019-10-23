#include "MonsterWorld.h"

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//콘솔창 커서의 위치를 변경하는 함수
void CursorView(char show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
//콘솔창 커서를 지우는 함수
bool Compare(Monster* temp1, Monster* temp2) {
	return temp1->NItem > temp2->NItem;
}
//정렬 기준이 되는 함수

void Monster::Print() {
	cout << "" << Name <<"	" << Icon << "	아이템 수 : " << NItem << "	에너지 : " << (NEnergy < 0 ? 0 : NEnergy) << "  \n";
}
//몬스터의 현제 상태를 출력하는 함수
void Monster::DeleteMove() {
	if (Behavior != NULL) {
		delete Behavior;
	}
}
//할당된 이동 알고리즘을 해제하는 함수
void Monster::Move() {
	Behavior->Move(x, y, NEnergy);
}
//할당된 이동 알고리즘을 실행시키는 함수
void Monster::SetMoveBehavior(MoveBehavior* temp) {
	DeleteMove();
	Behavior = temp;
}
//알맞은 이동 알고리즘을 할당시키는 함수


void Screen::StartScreen(vector<Monster*>& _Monsters) {
	int i, j;
	char ch = '0';
	cout << "[ Monster World (몬스터들의 세상) ]\n\n";
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			Map[j][i] = true;
			cout << "■";
		} cout << "\n";
	}
	for (auto& v : _Monsters) {
		if (Map[v->x][v->y]) {
			Map[v->x][v->y] = false;
			NItem--;
			v->NItem++;
			v->NEnergy += 8;
		}
		else v->NEnergy--;
		gotoxy(v->x * 2, v->y + 2);
		cout << v->Icon;
	}
	gotoxy(0, 10);
	cout << "전체 이동 횟수 = " << NMove << "  \n";
	cout << "남은 아이템 갯수 = " << NItem << "  \n";
	gotoxy(0, 13);
	sort(_Monsters.begin(), _Monsters.end(), Compare);
	for (auto& v : _Monsters) v->Print();
	gotoxy(0, _Monsters.size() + 14);
	cout << "앤터를 누르세요 . ";
	while (ch != 13) ch = _getch();
	Sleep(500);
	system("cls");
}
//시작 화면을 출력하는 함수
void Screen::Update(vector<Monster*>& _Monsters) {
	gotoxy(0, 0);
	int i, j;
	bool IsDead = false;
	vector<Monster*>::iterator Iter;
	NMove++;
	cout << "[ Monster World (몬스터들의 세상) ]\n\n";
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			cout << ((Map[j][i] == true) ? "■" : "ㆍ");
		} cout << "\n";
	}
	for (Iter = _Monsters.begin(); Iter != _Monsters.end();) {
		(*Iter)->Move();
		if (Map[(*Iter)->x][(*Iter)->y]) {
			Map[(*Iter)->x][(*Iter)->y] = false;
			NItem--;
			(*Iter)->NItem++;
			(*Iter)->NEnergy += 8;
		}
		else {
			(*Iter)->NEnergy--;
			if ((*Iter)->NEnergy <= 0) {
				IsDead = true;
				Iter = _Monsters.erase(Iter);
				if(Iter != _Monsters.begin()) Iter--;
				NDead++;
				continue;
			}
		}
		gotoxy((*Iter)->x * 2, (*Iter)->y + 2);
		cout << (*Iter)->Icon;
		if (!IsDead) Iter++;
		IsDead = false;
	}
	gotoxy(0, 10);
	cout << "전체 이동 횟수 = " << NMove << "  \n";
	cout << "남은 아이템 갯수 = " << NItem << "  \n";
	gotoxy(0, 13);
	sort(_Monsters.begin(), _Monsters.end(), Compare);
	for (auto& v : _Monsters) v->Print();
	for (int i = 0; i < NDead; i++) cout << "                                                       \n";
	Sleep(100);
}
//전체적인 게임을 진행시키는 함수