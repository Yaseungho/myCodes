#include "MonsterWorld.h"

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//�ܼ�â Ŀ���� ��ġ�� �����ϴ� �Լ�
void CursorView(char show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
//�ܼ�â Ŀ���� ����� �Լ�
bool Compare(Monster* temp1, Monster* temp2) {
	return temp1->NItem > temp2->NItem;
}
//���� ������ �Ǵ� �Լ�

void Monster::Print() {
	cout << "" << Name <<"	" << Icon << "	������ �� : " << NItem << "	������ : " << (NEnergy < 0 ? 0 : NEnergy) << "  \n";
}
//������ ���� ���¸� ����ϴ� �Լ�
void Monster::DeleteMove() {
	if (Behavior != NULL) {
		delete Behavior;
	}
}
//�Ҵ�� �̵� �˰����� �����ϴ� �Լ�
void Monster::Move() {
	Behavior->Move(x, y, NEnergy);
}
//�Ҵ�� �̵� �˰����� �����Ű�� �Լ�
void Monster::SetMoveBehavior(MoveBehavior* temp) {
	DeleteMove();
	Behavior = temp;
}
//�˸��� �̵� �˰����� �Ҵ��Ű�� �Լ�


void Screen::StartScreen(vector<Monster*>& _Monsters) {
	int i, j;
	char ch = '0';
	cout << "[ Monster World (���͵��� ����) ]\n\n";
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			Map[j][i] = true;
			cout << "��";
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
	cout << "��ü �̵� Ƚ�� = " << NMove << "  \n";
	cout << "���� ������ ���� = " << NItem << "  \n";
	gotoxy(0, 13);
	sort(_Monsters.begin(), _Monsters.end(), Compare);
	for (auto& v : _Monsters) v->Print();
	gotoxy(0, _Monsters.size() + 14);
	cout << "���͸� �������� . ";
	while (ch != 13) ch = _getch();
	Sleep(500);
	system("cls");
}
//���� ȭ���� ����ϴ� �Լ�
void Screen::Update(vector<Monster*>& _Monsters) {
	gotoxy(0, 0);
	int i, j;
	bool IsDead = false;
	vector<Monster*>::iterator Iter;
	NMove++;
	cout << "[ Monster World (���͵��� ����) ]\n\n";
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			cout << ((Map[j][i] == true) ? "��" : "��");
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
	cout << "��ü �̵� Ƚ�� = " << NMove << "  \n";
	cout << "���� ������ ���� = " << NItem << "  \n";
	gotoxy(0, 13);
	sort(_Monsters.begin(), _Monsters.end(), Compare);
	for (auto& v : _Monsters) v->Print();
	for (int i = 0; i < NDead; i++) cout << "                                                       \n";
	Sleep(100);
}
//��ü���� ������ �����Ű�� �Լ�